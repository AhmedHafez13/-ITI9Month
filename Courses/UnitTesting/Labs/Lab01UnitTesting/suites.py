import unittest
import test


def run_suite_1():
    suite1 = unittest.TestSuite()
    suite1.addTest(unittest.makeSuite(test.TestNumbers))
    runner1 = unittest.TextTestRunner()
    runner1.run(suite1)


def run_suite_2():
    suite2 = unittest.TestSuite()
    suite2.addTest(unittest.makeSuite(test.TestStringMethods))
    runner2 = unittest.TextTestRunner()
    runner2.run(suite2)


"""
Result of running 'suite1'
-----
from TestNumbers->setUp
from test_is_odd #2
from TestNumbers->tearDown

from TestNumbers->setUp
from test_odd_even #1
from TestNumbers->tearDown
"""
run_suite_1()

"""
Result of running 'suite1'
-----
from test_existence #3
from test_existence2 #4
"""
run_suite_2()
