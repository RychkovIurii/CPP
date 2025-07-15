import subprocess
import os
import random

EXE = os.path.join(os.path.dirname(__file__), "PmergeMe")


def build():
    subprocess.run(["make", "re"], cwd=os.path.dirname(__file__), check=True)


def run_cmd(args):
    cmd = [EXE] + [str(a) for a in args]
    return subprocess.run(cmd, capture_output=True, text=True)


def parse_after(output):
    for line in output.splitlines():
        if line.startswith("After:"):
            numbers = line.split(":", 1)[1].strip()
            if numbers:
                return [int(x) for x in numbers.split()]
            return []
    return []


def test_small():
    args = [3, 5, 9, 7, 4]
    res = run_cmd(args)
    assert res.returncode == 0, res.stderr
    assert parse_after(res.stdout) == sorted(args)
    print("✅ small input")


def test_large():
    args = [random.randint(1, 100000) for _ in range(3000)]
    res = run_cmd(args)
    assert res.returncode == 0, res.stderr
    assert parse_after(res.stdout) == sorted(args)
    print("✅ large input")


def test_invalid():
    res = run_cmd(["-1", "2"])
    assert res.returncode != 0
    assert res.stderr
    print("✅ invalid input")


def test_empty():
    """Test with no arguments"""
    res = run_cmd([])
    assert res.returncode == 0  # Should show usage, not error
    assert "Usage:" in res.stdout
    print("✅ empty input")


def test_single_element():
    """Test with single element"""
    res = run_cmd([42])
    assert res.returncode == 0, res.stderr
    assert parse_after(res.stdout) == [42]
    print("✅ single element")


def test_two_elements():
    """Test with two elements"""
    res = run_cmd([5, 3])
    assert res.returncode == 0, res.stderr
    assert parse_after(res.stdout) == [3, 5]
    print("✅ two elements")


def test_already_sorted():
    """Test with already sorted input"""
    args = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    res = run_cmd(args)
    assert res.returncode == 0, res.stderr
    assert parse_after(res.stdout) == sorted(args)
    print("✅ already sorted")


def test_reverse_sorted():
    """Test with reverse sorted input"""
    args = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
    res = run_cmd(args)
    assert res.returncode == 0, res.stderr
    assert parse_after(res.stdout) == sorted(args)
    print("✅ reverse sorted")


def test_duplicates():
    """Test with duplicate numbers"""
    args = [5, 3, 5, 1, 3, 8, 1, 5]
    res = run_cmd(args)
    assert res.returncode == 0, res.stderr
    assert parse_after(res.stdout) == sorted(args)
    print("✅ duplicates")


def test_all_same():
    """Test with all identical numbers"""
    args = [7, 7, 7, 7, 7]
    res = run_cmd(args)
    assert res.returncode == 0, res.stderr
    assert parse_after(res.stdout) == sorted(args)
    print("✅ all same numbers")


def test_max_int():
    """Test with maximum integer values"""
    max_int = 2147483647  # INT_MAX
    args = [max_int, max_int - 1, max_int - 2, 1]
    res = run_cmd(args)
    assert res.returncode == 0, res.stderr
    assert parse_after(res.stdout) == sorted(args)
    print("✅ max int values")


def test_zero():
    """Test with zero values"""
    args = [0, 5, 0, 3, 0]
    res = run_cmd(args)
    assert res.returncode == 0, res.stderr
    assert parse_after(res.stdout) == sorted(args)
    print("✅ zero values")


def test_invalid_negative():
    """Test with negative numbers"""
    res = run_cmd(["-1", "2"])
    assert res.returncode != 0
    assert res.stderr
    print("✅ negative numbers rejected")


def test_invalid_letters():
    """Test with letters in numbers"""
    res = run_cmd(["12a", "5"])
    assert res.returncode != 0
    assert res.stderr
    print("✅ letters in numbers rejected")


def test_invalid_symbols():
    """Test with symbols in input"""
    res = run_cmd(["1@2", "5"])
    assert res.returncode != 0
    assert res.stderr
    print("✅ symbols rejected")


def test_invalid_floating_point():
    """Test with floating point numbers"""
    res = run_cmd(["1.5", "2"])
    assert res.returncode != 0
    assert res.stderr
    print("✅ floating point rejected")


def test_invalid_empty_string():
    """Test with empty string argument"""
    res = run_cmd(["", "5"])
    assert res.returncode != 0
    assert res.stderr
    print("✅ empty string rejected")


def test_invalid_plus_only():
    """Test with just plus sign"""
    res = run_cmd(["+", "5"])
    assert res.returncode != 0
    assert res.stderr
    print("✅ plus sign only rejected")


def test_invalid_minus_only():
    """Test with just minus sign"""
    res = run_cmd(["-", "5"])
    assert res.returncode != 0
    assert res.stderr
    print("✅ minus sign only rejected")


def test_valid_plus_prefix():
    """Test with valid plus prefix"""
    args = ["+5", "+3", "+7"]
    res = run_cmd(args)
    assert res.returncode == 0, res.stderr
    assert parse_after(res.stdout) == [3, 5, 7]
    print("✅ plus prefix accepted")


def test_large_number_overflow():
    """Test with number larger than INT_MAX"""
    overflow_num = "2147483648"  # INT_MAX + 1
    res = run_cmd([overflow_num, "5"])
    assert res.returncode != 0
    assert res.stderr
    print("✅ overflow number rejected")


def test_very_large_input():
    """Test with very large valid input set"""
    args = [random.randint(1, 1000000) for _ in range(5000)]
    res = run_cmd(args)
    assert res.returncode == 0, res.stderr
    result = parse_after(res.stdout)
    assert result == sorted(args)
    assert len(result) == len(args)
    print("✅ very large input (5000 elements)")


def test_performance_output():
    """Test that performance timing is included in output"""
    args = [random.randint(1, 1000) for _ in range(100)]
    res = run_cmd(args)
    assert res.returncode == 0, res.stderr
    output = res.stdout
    assert "Time to process" in output
    assert "std::vector" in output
    assert "std::deque" in output
    assert "us" in output  # microseconds
    print("✅ performance output format")


def test_leading_zeros():
    """Test with leading zeros"""
    args = ["007", "0005", "00001"]
    res = run_cmd(args)
    assert res.returncode == 0, res.stderr
    assert parse_after(res.stdout) == [1, 5, 7]
    print("✅ leading zeros")


def test_whitespace_in_args():
    """Test that individual arguments don't contain spaces (should be handled by shell)"""
    # This test verifies our program doesn't need to handle internal whitespace
    # since arguments are split by the shell
    args = ["1", "2", "3"]
    res = run_cmd(args)
    assert res.returncode == 0, res.stderr
    assert parse_after(res.stdout) == [1, 2, 3]
    print("✅ normal arguments (no internal whitespace)")


def test_consecutive_duplicates():
    """Test with many consecutive duplicates"""
    args = [1, 1, 1, 2, 2, 2, 3, 3, 3]
    res = run_cmd(args)
    assert res.returncode == 0, res.stderr
    assert parse_after(res.stdout) == sorted(args)
    print("✅ consecutive duplicates")


def test_alternating_pattern():
    """Test with alternating high-low pattern"""
    args = [100, 1, 99, 2, 98, 3, 97, 4]
    res = run_cmd(args)
    assert res.returncode == 0, res.stderr
    assert parse_after(res.stdout) == sorted(args)
    print("✅ alternating pattern")


def test_performance_comparison():
    """Test that both vector and deque times are reported"""
    args = [random.randint(1, 1000) for _ in range(1000)]
    res = run_cmd(args)
    assert res.returncode == 0, res.stderr
    
    lines = res.stdout.splitlines()
    vector_time_line = None
    deque_time_line = None
    
    for line in lines:
        if "std::vector" in line and "Time to process" in line:
            vector_time_line = line
        elif "std::deque" in line and "Time to process" in line:
            deque_time_line = line
    
    assert vector_time_line is not None, "Vector timing line not found"
    assert deque_time_line is not None, "Deque timing line not found"
    assert "us" in vector_time_line, "Vector time should be in microseconds"
    assert "us" in deque_time_line, "Deque time should be in microseconds"
    
    print("✅ performance comparison output")


def test_boundary_values():
    """Test with boundary values around common limits"""
    args = [0, 1, 2, 255, 256, 65535, 65536, 1000000]
    res = run_cmd(args)
    assert res.returncode == 0, res.stderr
    assert parse_after(res.stdout) == sorted(args)
    print("✅ boundary values")


def test_subject_requirement_3000():
    """Test specifically with 3000+ elements as mentioned in subject"""
    args = [random.randint(1, 100000) for _ in range(3000)]
    res = run_cmd(args)
    assert res.returncode == 0, res.stderr
    result = parse_after(res.stdout)
    assert result == sorted(args)
    assert len(result) == 3000
    
    # Verify timing output mentions the correct count
    assert "3000 elements" in res.stdout
    print("✅ subject requirement: 3000 elements")


def test_extreme_performance():
    """Test with maximum reasonable input size"""
    print("Running extreme performance test (10000 elements)...")
    args = [random.randint(1, 1000000) for _ in range(10000)]
    res = run_cmd(args)
    assert res.returncode == 0, res.stderr
    result = parse_after(res.stdout)
    assert result == sorted(args)
    assert len(result) == 10000
    print("✅ extreme performance test")


def run_all_tests():
    """Run all test functions"""
    test_functions = [
        test_empty,
        test_single_element,
        test_two_elements,
        test_small,
        test_already_sorted,
        test_reverse_sorted,
        test_duplicates,
        test_all_same,
        test_max_int,
        test_zero,
        test_large,
        test_subject_requirement_3000,
        test_very_large_input,
        test_extreme_performance,
        test_performance_output,
        test_performance_comparison,
        # Invalid input tests
        test_invalid_negative,
        test_invalid_letters,
        test_invalid_symbols,
        test_invalid_floating_point,
        test_invalid_empty_string,
        test_invalid_plus_only,
        test_invalid_minus_only,
        test_large_number_overflow,
        # Valid edge cases
        test_valid_plus_prefix,
        test_leading_zeros,
        test_whitespace_in_args,
        test_consecutive_duplicates,
        test_alternating_pattern,
        test_boundary_values,
        # Subject requirement tests
        test_subject_requirement_3000,
        test_extreme_performance,
    ]
    
    print("Running comprehensive PmergeMe tests...\n")
    
    for test_func in test_functions:
        try:
            test_func()
        except Exception as e:
            print(f"❌ {test_func.__name__} failed: {e}")
            return False
    
    print(f"\n🎉 All {len(test_functions)} tests passed!")
    return True


if __name__ == "__main__":
    build()
    success = run_all_tests()
    if not success:
        exit(1)