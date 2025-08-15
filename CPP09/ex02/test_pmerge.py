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

def parse_comparisons(output):
    actual_vec = actual_deq = max_comp = None
    for line in output.splitlines():
        if line.startswith("Actual vector comparisons:"):
            actual_vec = int(line.split(":", 1)[1].strip())
        elif line.startswith("Actual deque comparisons:"):
            actual_deq = int(line.split(":", 1)[1].strip())
        elif line.startswith("Max comparisons F(n):"):
            max_comp = int(line.split(":", 1)[1].strip())
    return actual_vec, actual_deq, max_comp


def test_small():
    args = [3, 5, 9, 7, 4]
    res = run_cmd(args)
    assert res.returncode == 0, res.stderr
    assert parse_after(res.stdout) == sorted(args)
    
    # Check comparison counts
    actual_vec, actual_deq, max_comp = parse_comparisons(res.stdout)
    if actual_vec is not None and max_comp is not None:
        assert actual_vec <= max_comp, f"Vector comparisons {actual_vec} exceed maximum {max_comp} for input {args}"
    if actual_deq is not None and max_comp is not None:
        assert actual_deq <= max_comp, f"Deque comparisons {actual_deq} exceed maximum {max_comp} for input {args}"
    print("✅ small input")


def test_large():
    args = [random.randint(1, 100000) for _ in range(3000)]
    res = run_cmd(args)
    assert res.returncode == 0, res.stderr
    assert parse_after(res.stdout) == sorted(args)
    
    # Check comparison counts for large input
    actual_vec, actual_deq, max_comp = parse_comparisons(res.stdout)
    if actual_vec is not None and max_comp is not None:
        assert actual_vec <= max_comp, f"Vector comparisons {actual_vec} exceed maximum {max_comp} for {len(args)} elements"
    if actual_deq is not None and max_comp is not None:
        assert actual_deq <= max_comp, f"Deque comparisons {actual_deq} exceed maximum {max_comp} for {len(args)} elements"
    print("✅ large input")


def test_comparison_validation():
    """Test that comparison counts don't exceed theoretical maximum"""
    test_cases = [
        [1],
        [2, 1],
        [3, 1, 2],
        [5, 3, 1, 4, 2],
		[3, 5, 9, 7, 4],  # n=5
        [8, 7, 6, 5, 4, 3, 2, 1],
		list(range(10, 0, -1)),  # n=10, reverse sorted
        list(range(20, 0, -1)),  # reverse sorted
		[5] * 15,  # n=15, all duplicates
        [12, 5, 7, 3, 8, 6, 1, 4, 10, 2, 9],  # n=11, check full batch
        list(range(1, 21)),       # already sorted
		[random.randint(1, 1000) for _ in range(50)],  # n=50, random
        [random.randint(1, 1000) for _ in range(100)]
    ]
    
    for args in test_cases:
        res = run_cmd(args)
        assert res.returncode == 0, f"Failed on input: {args}. Error: {res.stderr}"
        assert parse_after(res.stdout) == sorted(args)
        
        actual_vec, actual_deq, max_comp = parse_comparisons(res.stdout)
        
        if actual_vec is not None and max_comp is not None:
            assert actual_vec <= max_comp, f"Vector comparisons {actual_vec} exceed maximum {max_comp} for input: {args}"
        if actual_deq is not None and max_comp is not None:
            assert actual_deq <= max_comp, f"Deque comparisons {actual_deq} exceed maximum {max_comp} for input: {args}"
    
    print("✅ comparison validation")


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
    
    # Check comparison counts - sorted input should be efficient
    actual_vec, actual_deq, max_comp = parse_comparisons(res.stdout)
    if actual_vec is not None and max_comp is not None:
        assert actual_vec <= max_comp, f"Vector comparisons {actual_vec} exceed maximum {max_comp}"
    if actual_deq is not None and max_comp is not None:
        assert actual_deq <= max_comp, f"Deque comparisons {actual_deq} exceed maximum {max_comp}"
    print("✅ already sorted")


def test_reverse_sorted():
    """Test with reverse sorted input"""
    args = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
    res = run_cmd(args)
    assert res.returncode == 0, res.stderr
    assert parse_after(res.stdout) == sorted(args)
    
    # Check comparison counts - reverse sorted is worst case
    actual_vec, actual_deq, max_comp = parse_comparisons(res.stdout)
    if actual_vec is not None and max_comp is not None:
        assert actual_vec <= max_comp, f"Vector comparisons {actual_vec} exceed maximum {max_comp}"
    if actual_deq is not None and max_comp is not None:
        assert actual_deq <= max_comp, f"Deque comparisons {actual_deq} exceed maximum {max_comp}"
    print("✅ reverse sorted")


def test_duplicates():
    """Test with duplicate numbers"""
    args = [5, 3, 5, 1, 3, 8, 1, 5]
    res = run_cmd(args)
    assert res.returncode == 0, f"Failed on duplicates: {args}. Error: {res.stderr}"
    assert parse_after(res.stdout) == sorted(args)
    
    # Check comparison counts
    actual_vec, actual_deq, max_comp = parse_comparisons(res.stdout)
    if actual_vec is not None and max_comp is not None:
        assert actual_vec <= max_comp, f"Vector comparisons {actual_vec} exceed maximum {max_comp} for duplicates: {args}"
    if actual_deq is not None and max_comp is not None:
        assert actual_deq <= max_comp, f"Deque comparisons {actual_deq} exceed maximum {max_comp} for duplicates: {args}"
    
    print("✅ duplicates")


def test_all_same():
    """Test with all identical numbers"""
    args = [7, 7, 7, 7, 7]
    res = run_cmd(args)
    assert res.returncode == 0, f"Failed on all same: {args}. Error: {res.stderr}"
    assert parse_after(res.stdout) == sorted(args)
    
    # Check comparison counts
    actual_vec, actual_deq, max_comp = parse_comparisons(res.stdout)
    if actual_vec is not None and max_comp is not None:
        assert actual_vec <= max_comp, f"Vector comparisons {actual_vec} exceed maximum {max_comp} for all same: {args}"
    if actual_deq is not None and max_comp is not None:
        assert actual_deq <= max_comp, f"Deque comparisons {actual_deq} exceed maximum {max_comp} for all same: {args}"
    
    print("✅ all same numbers")


def test_max_int():
    """Test with maximum integer values"""
    max_int = 2147483647  # INT_MAX
    args = [max_int, max_int - 1, max_int - 2, 1]
    res = run_cmd(args)
    assert res.returncode == 0, f"Failed on max int: {args}. Error: {res.stderr}"
    assert parse_after(res.stdout) == sorted(args)
    
    # Check comparison counts
    actual_vec, actual_deq, max_comp = parse_comparisons(res.stdout)
    if actual_vec is not None and max_comp is not None:
        assert actual_vec <= max_comp, f"Vector comparisons {actual_vec} exceed maximum {max_comp} for max int: {args}"
    if actual_deq is not None and max_comp is not None:
        assert actual_deq <= max_comp, f"Deque comparisons {actual_deq} exceed maximum {max_comp} for max int: {args}"
    
    print("✅ max int values")


def test_zero():
    """Test with zero values"""
    args = [0, 5, 0, 3, 0]
    res = run_cmd(args)
    assert res.returncode == 0, f"Failed on zero values: {args}. Error: {res.stderr}"
    assert parse_after(res.stdout) == sorted(args)
    
    # Check comparison counts
    actual_vec, actual_deq, max_comp = parse_comparisons(res.stdout)
    if actual_vec is not None and max_comp is not None:
        assert actual_vec <= max_comp, f"Vector comparisons {actual_vec} exceed maximum {max_comp} for zero values: {args}"
    if actual_deq is not None and max_comp is not None:
        assert actual_deq <= max_comp, f"Deque comparisons {actual_deq} exceed maximum {max_comp} for zero values: {args}"
    
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
    assert res.returncode == 0, f"Failed on very large input ({len(args)} elements). Error: {res.stderr}"
    result = parse_after(res.stdout)
    assert result == sorted(args), f"Sorting failed for very large input ({len(args)} elements)"
    assert len(result) == len(args)
    
    # Check comparison counts for very large input
    actual_vec, actual_deq, max_comp = parse_comparisons(res.stdout)
    if actual_vec is not None and max_comp is not None:
        assert actual_vec <= max_comp, f"Vector comparisons {actual_vec} exceed maximum {max_comp} for large input ({len(args)} elements)"
    if actual_deq is not None and max_comp is not None:
        assert actual_deq <= max_comp, f"Deque comparisons {actual_deq} exceed maximum {max_comp} for large input ({len(args)} elements)"
    
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
    
    # Check comparison counts for 3000 elements
    actual_vec, actual_deq, max_comp = parse_comparisons(res.stdout)
    if actual_vec is not None and max_comp is not None:
        assert actual_vec <= max_comp, f"Vector comparisons {actual_vec} exceed maximum {max_comp} for 3000 elements"
        efficiency = (actual_vec / max_comp) * 100
        print(f"  Vector efficiency: {actual_vec}/{max_comp} ({efficiency:.1f}%)")
    if actual_deq is not None and max_comp is not None:
        assert actual_deq <= max_comp, f"Deque comparisons {actual_deq} exceed maximum {max_comp} for 3000 elements"
        efficiency = (actual_deq / max_comp) * 100
        print(f"  Deque efficiency: {actual_deq}/{max_comp} ({efficiency:.1f}%)")
    
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
    """Run all test functions and collect results"""
    test_functions = [
        test_empty,  # Note: it's test_empty not test_empty_input
        test_single_element,
        test_two_elements,
        test_small,
        test_comparison_validation,
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
    ]
    
    print("Running comprehensive PmergeMe tests...\n")
    
    passed_tests = []
    failed_tests = []
    
    for test_func in test_functions:
        try:
            test_func()
            passed_tests.append(test_func.__name__)
        except Exception as e:
            print(f"❌ {test_func.__name__} failed: {e}")
            failed_tests.append((test_func.__name__, str(e)))
    
    # Print summary
    print(f"\n{'='*60}")
    print(f"TEST SUMMARY")
    print(f"{'='*60}")
    print(f"✅ Passed: {len(passed_tests)}")
    print(f"❌ Failed: {len(failed_tests)}")
    print(f"📊 Total:  {len(test_functions)}")
    
    if failed_tests:
        print(f"\n{'='*60}")
        print("FAILED TESTS:")
        print(f"{'='*60}")
        for test_name, error in failed_tests:
            print(f"❌ {test_name}: {error}")
    
    if passed_tests:
        print(f"\n{'='*60}")
        print("PASSED TESTS:")
        print(f"{'='*60}")
        for test_name in passed_tests:
            print(f"✅ {test_name}")
    
    success_rate = len(passed_tests) / len(test_functions) * 100
    print(f"\n🎯 Success Rate: {success_rate:.1f}%")
    
    if len(failed_tests) == 0:
        print(f"🎉 All tests passed!")
        return True
    else:
        print(f"⚠️  {len(failed_tests)} test(s) failed.")
        return False


if __name__ == "__main__":
    build()
    success = run_all_tests()
    if not success:
        exit(1)