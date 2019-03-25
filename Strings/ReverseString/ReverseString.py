import unittest

#strings are immutable in python, so let's assume the string has been already converted in a
#list of characters

def reverse(listOfChars):

  i = 0
  j = len(listOfChars)-1;

  while i < j :
      listOfChars[i], listOfChars[j] = listOfChars[j], listOfChars[i]
      i = i+1
      j = j-1
      
pass

class Test(unittest.TestCase):

    def test_empty_string(self):
        listOfChars = []
        reverse(listOfChars)
        expected = []
        self.assertEqual(listOfChars, expected)

    def test_single_character_string(self):
        listOfChars = ['A']
        reverse(listOfChars)
        expected = ['A']
        self.assertEqual(listOfChars, expected)

    def test_longer_string(self):
        listOfChars = ['A', 'B', 'C', 'D', 'E']
        reverse(listOfChars)
        expected = ['E', 'D', 'C', 'B', 'A']
        self.assertEqual(listOfChars, expected)


unittest.main(verbosity=2)
