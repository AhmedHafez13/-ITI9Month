import unittest

import app


class TestNumbers(unittest.TestCase):
    def setUp(self) -> None:
        print("from TestNumbers->setUp")

    def tearDown(self) -> None:
        print("from TestNumbers->tearDown")

    def test_odd_even(self):
        print("from test_odd_even #1")
        self.assertEqual(app.odd_or_even(4), "even")
        self.assertEqual(app.odd_or_even(3), "odd")
        self.assertNotEqual(app.odd_or_even(0), "even")

    def test_is_odd(self):
        print("from test_is_odd #2")
        self.assertTrue(app.is_odd_number(5))
        self.assertFalse(app.is_odd_number(6))


class TestStringMethods(unittest.TestCase):
    def test_existence(self):
        print("from test_existence #3")
        key = "ITI"
        text = "ITI stands for Industrial Training Institutes"
        self.assertIn(key, text)

    def test_existence2(self):
        print("from test_existence2 #4")
        key = "not exists"
        text = "ITI stands for Industrial Training Institutes"
        self.assertIn(key, text)


if __name__ == '__main__':
    unittest.main()
