import unittest
from main import calculate_day_offset


class TestStringMethods(unittest.TestCase):
    def test_calculate_day_offset(self):
        self.assertEqual(12, calculate_day_offset(1470041138))
        self.assertEqual(0, calculate_day_offset(1468997420))
        self.assertEqual(-1, calculate_day_offset(1468911019))

if __name__ == '__main__':
    unittest.main()