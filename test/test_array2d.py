import unittest
from dfndarray import DoubleArray2D, Array2DComputeTestValue

class TestArray2DBase:
    """Tests to pass whatever Array2D allocation method is"""

    def test_str(self):
        expected_re = "<Array2D of shape \(2,3\) at 0x\w*>"
        s = '%s' % self.a
        self.assertRegexpMatches(s, expected_re)

    def test_getitem(self):
        for i0 in range(2):
            for i1 in range(3):
                self.assertEqual(self.a[i0,i1], i0*10+i1)

    def test_size(self):
        self.assertEqual(self.a.n0(), 2)
        self.assertEqual(self.a.n1(), 3)
        self.assertEqual(self.a.dim(0), 2)
        self.assertEqual(self.a.dim(1), 3)
        self.assertEqual(self.a.size(), 6)

    def test_out_of_bounds(self):
        regexp = "expected 'i0 < m_n0', but got: '10 >= 2'"
        self.assertRaisesRegexp(RuntimeError, regexp,
                                self.a.__getitem__, (10,0))

        regexp = "expected 'i1 < m_n1', but got: '10 >= 3'"
        self.assertRaisesRegexp(RuntimeError, regexp,
                                self.a.__getitem__, (0,10))

    def test_fill(self):
        self.a.fill(7)
        for i0 in range(2):
            for i1 in range(3):
                self.assertEqual(self.a[i0,i1], 7)

    def test_resize_equal(self):
        self.a.resize(2,3)

        for i0 in range(2):
            for i1 in range(3):
                self.assertEqual(self.a[i0,i1], i0*10+i1)

        self.assertEqual(self.a.n0(), 2)
        self.assertEqual(self.a.n1(), 3)
        self.assertEqual(self.a.dim(0), 2)
        self.assertEqual(self.a.dim(1), 3)
        self.assertEqual(self.a.size(), 6)

    def test_resize_less(self):

        self.a.resize(3,1)

        self.assertEqual(self.a[0,0], 0.)
        self.assertEqual(self.a[1,0], 1.)
        self.assertEqual(self.a[2,0], 2.)

        self.assertEqual(self.a.n0(), 3)
        self.assertEqual(self.a.n1(), 1)
        self.assertEqual(self.a.dim(0), 3)
        self.assertEqual(self.a.dim(1), 1)
        self.assertEqual(self.a.size(), 3)

    def test_resize_greater(self):

        self.a.resize(2,4)

        self.assertEqual(self.a[0,0], 0.)
        self.assertEqual(self.a[0,1], 1.)
        self.assertEqual(self.a[0,2], 2.)
        self.assertEqual(self.a[0,3], 10.)
        self.assertEqual(self.a[1,0], 11.)
        self.assertEqual(self.a[1,1], 12.)
        self.assertEqual(self.a[1,2], 0.)
        self.assertEqual(self.a[1,3], 0.)

        self.assertEqual(self.a.n0(), 2)
        self.assertEqual(self.a.n1(), 4)
        self.assertEqual(self.a.dim(0), 2)
        self.assertEqual(self.a.dim(1), 4)
        self.assertEqual(self.a.size(), 8)

    def test_reallocate(self):
        self.assertRaises(RuntimeError,self.a.allocate,4,4)

class TestArray2DAllocateConstructor(unittest.TestCase, TestArray2DBase):
    """Test Array2D allocated in constructor"""

    def setUp(self):
        self.a = DoubleArray2D(2,3)
        f = Array2DComputeTestValue()
        self.a.fill(f)

class TestArray2DAllocateMethod(unittest.TestCase, TestArray2DBase):
    """Test Array2D allocated in constructor method"""

    def setUp(self):
        self.a = DoubleArray2D()
        self.a.allocate(2,3)
        f = Array2DComputeTestValue()
        self.a.fill(f)

class TestArray2DNotAllocated(unittest.TestCase):

    def setUp(self):
        self.a = DoubleArray2D()

    def test_str(self):
        expected_re = "<Array2D not allocated>"
        s = '%s' % self.a
        self.assertRegexpMatches(s, expected_re)

    def test_getitem(self):
        self.assertRaises(RuntimeError,self.a.__getitem__,(0,0))

    def test_size(self):
        self.assertEqual(self.a.n0(), 0)
        self.assertEqual(self.a.n1(), 0)
        self.assertEqual(self.a.dim(0), 0)
        self.assertEqual(self.a.dim(1), 0)
        self.assertEqual(self.a.size(), 0)

    def test_fill(self):
        self.assertRaises(RuntimeError,self.a.fill,7)

    def test_resize(self):
        self.assertRaises(RuntimeError,self.a.resize,4,8)

if __name__ == '__main__':
    unittest.main()
