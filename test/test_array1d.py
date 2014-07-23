import unittest
from dfndarray import DoubleArray1D, Array1DComputeTestValue

class TestArray1DBase:
    """Tests to pass whatever Array1D allocation method is"""

    def test_str(self):
        expected_re = "<Array1D of shape \(4\) at 0x\w*>"
        s = '%s' % self.a
        self.assertRegexpMatches(s, expected_re)

    def test_getitem(self):
        self.assertEqual(self.a[0], 0.)
        self.assertEqual(self.a[1], 1.)
        self.assertEqual(self.a[2], 2.)
        self.assertEqual(self.a[3], 3.)

    def test_size(self):
        self.assertEqual(self.a.n0(), 4)
        self.assertEqual(self.a.dim(0), 4)
        self.assertEqual(self.a.size(), 4)

    def test_out_of_bounds(self):
        regexp = "expected 'i0 < m_n0', but got: '10 >= 4'"
        self.assertRaisesRegexp(RuntimeError, regexp, self.a.__getitem__,10)

    def test_fill(self):
        self.a.fill(7)
        self.assertEqual(self.a[0], 7.)
        self.assertEqual(self.a[1], 7.)
        self.assertEqual(self.a[2], 7.)
        self.assertEqual(self.a[3], 7.)

    def test_resize_equal(self):
        self.a.resize(4)

        self.assertEqual(self.a[0], 0.)
        self.assertEqual(self.a[1], 1.)
        self.assertEqual(self.a[2], 2.)
        self.assertEqual(self.a[3], 3.)

        self.assertEqual(self.a.n0(), 4)
        self.assertEqual(self.a.dim(0), 4)
        self.assertEqual(self.a.size(), 4)

    def test_resize_less(self):

        self.a.resize(2)

        self.assertEqual(self.a[0], 0.)
        self.assertEqual(self.a[1], 1.)

        self.assertEqual(self.a.n0(), 2)
        self.assertEqual(self.a.dim(0), 2)
        self.assertEqual(self.a.size(), 2)

    def test_resize_greater(self):

        self.a.resize(6)

        self.assertEqual(self.a[0], 0.)
        self.assertEqual(self.a[1], 1.)
        self.assertEqual(self.a[2], 2.)
        self.assertEqual(self.a[3], 3.)
        self.assertEqual(self.a[4], 0.)
        self.assertEqual(self.a[5], 0.)

        self.assertEqual(self.a.n0(), 6)
        self.assertEqual(self.a.dim(0), 6)
        self.assertEqual(self.a.size(), 6)

    def test_reallocate(self):
        self.assertRaises(RuntimeError,self.a.allocate,4)

class TestArray1DAllocateConstructor(unittest.TestCase, TestArray1DBase):
    """Test Array1D allocated in constructor"""

    def setUp(self):
        self.a = DoubleArray1D(4)
        f = Array1DComputeTestValue()
        self.a.fill(f)

class TestArray1DAllocateMethod(unittest.TestCase, TestArray1DBase):
    """Test Array1D allocated in constructor method"""

    def setUp(self):
        self.a = DoubleArray1D()
        self.a.allocate(4)
        f = Array1DComputeTestValue()
        self.a.fill(f)

class TestArray1DAllocateResize(unittest.TestCase, TestArray1DBase):
    """Test Array1D allocated in constructor method"""

    def setUp(self):
        self.a = DoubleArray1D()
        self.a.resize(4)
        f = Array1DComputeTestValue()
        self.a.fill(f)

class TestArray1DNotAllocated(unittest.TestCase):

    def setUp(self):
        self.a = DoubleArray1D()

    def test_str(self):
        expected_re = "<Array1D not allocated>"
        s = '%s' % self.a
        self.assertRegexpMatches(s, expected_re)

    def test_getitem(self):
        self.assertRaises(RuntimeError,self.a.__getitem__,0)

    def test_size(self):
        self.assertEqual(self.a.n0(), 0)
        self.assertEqual(self.a.dim(0), 0)
        self.assertEqual(self.a.size(), 0)

    def test_fill(self):
        self.assertRaises(RuntimeError,self.a.fill,7)

if __name__ == '__main__':
    unittest.main()
