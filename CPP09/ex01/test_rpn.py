import subprocess

def run_test(expr, expected_output=None, expect_error=False):
	print(f"Test: {expr}")
	try:
		result = subprocess.run(
			["./RPN", expr],
			capture_output=True,
			text=True,
			check=False
		)
		stdout = result.stdout.strip()
		stderr = result.stderr.strip()

		if expect_error:
			if stderr:
				print(f"✅ Got expected error: {stderr}")
			else:
				print(f"❌ Expected error but got: {stdout}")
		else:
			if stdout == str(expected_output):
				print(f"✅ Passed: {stdout}")
			else:
				print(f"❌ Failed: expected {expected_output}, got {stdout}")
	except Exception as e:
		print(f"❌ Exception while running test: {e}")
	print("-" * 40)


if __name__ == "__main__":
	# Valid expressions
	run_test("8 9 * 9 - 9 - 9 - 4 - 1 +", 42)
	run_test("7 7 * 7 -", 42)
	run_test("1 2 * 2 / 2 * 2 4 - +", 0)
	run_test("1 0 1 + +", 2)
	run_test("1 0 + 1 +", 2)

	# Invalid expressions
	run_test("(1 + 1)", expect_error=True)
	run_test("1 + 1", expect_error=True)
	run_test("1 2 + 3", expect_error=True)
	run_test("1 +", expect_error=True)
	run_test("1 2 + +", expect_error=True)
	run_test("a b c +", expect_error=True)
	run_test("a b +", expect_error=True)
	run_test("9 0 /", expect_error=True)  # division by zero
	run_test("1 10 +", expect_error=True)  # number should be less then 10

	# Overflow cases (2147483647 and -2147483648)
	run_test("2 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 *", expect_error=True)  # positive number overflow
	run_test("1 9 - 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 *", expect_error=True)  # negative number overflow
