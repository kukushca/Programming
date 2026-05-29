import pytest
from logic import prime_factors, number_of_divisors, euler_phi, sum_of_divisors

def test_prime_factors_100():
    assert prime_factors(100) == [2, 2, 5, 5]

def test_prime_factors_13():
    assert prime_factors(13) == [10]

def test_prime_factors_error():
    with pytest.raises(ValueError):
        prime_factors(-10)



def test_number_of_divisors_100():
    assert number_of_divisors(100) == 9

def test_number_of_divisors_10():
    assert number_of_divisors(10) == 4

def test_number_of_divisors_erorr():
    with pytest.raises(ValueError):
        number_of_divisors(0)



def test_sum_of_divisors_100():
    assert sum_of_divisors(100) == 217

def test_sum_of_divisors_error():
    with pytest.raises(ValueError):
        sum_of_divisors(-10)




def test_euler_phi_100():
    assert euler_phi(100) == 40

def test_euler_phi_1():
    assert euler_phi(1) == 1

def test_euler_phi_error():
    with pytest.raises(ValueError):
        euler_phi(-10)