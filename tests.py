import unittest
from main import calculate_day_offset


class TestStringMethods(unittest.TestCase):
    def test_calculate_day_offset(self):
        self.assertEqual(12, calculate_day_offset(1470041138))

if __name__ == '__main__':
    unittest.main()