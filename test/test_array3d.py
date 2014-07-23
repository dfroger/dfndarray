import unittest

import numpy as np

from dfndarray import DoubleArray3D, Array3DComputeTestValue

class TestArray3DBase:
    """Tests to pass whatever Array3D allocation method is"""

    def test_str(self):
        expected_re = "<Array3D of shape \(2,3,4\) at 0x\w*>"
        s = '%s' % self.a
        self.assertRegexpMatches(s, expected_re)

    def test_getitem(self):
        for i0 in range(2):
            for i1 in range(3):
                for i2 in range(3):
                    self.assertEqual(self.a[i0,i1,i2], i0*100 +i1*10 + i2)

    def test_size(self):
        self.assertEqual(self.a.n0(), 2)
        self.assertEqual(self.a.n1(), 3)
        self.assertEqual(self.a.n2(), 4)
        self.assertEqual(self.a.dim(0), 2)
        self.assertEqual(self.a.dim(1), 3)
        self.assertEqual(self.a.dim(2), 4)
        self.assertEqual(self.a.size(), 24)

    def test_out_of_bounds(self):
        regexp = "expected 'i0 < m_n0', but got: '10 >= 2'"
        self.assertRaisesRegexp(RuntimeError, regexp,
                                self.a.__getitem__, (10,0,0))

        regexp = "expected 'i1 < m_n1', but got: '10 >= 3'"
        self.assertRaisesRegexp(RuntimeError, regexp,
                                self.a.__getitem__, (0,10,0))

        regexp = "expected 'i2 < m_n2', but got: '10 >= 4'"
        self.assertRaisesRegexp(RuntimeError, regexp,
                                self.a.__getitem__, (0,0,10))

    def test_fill(self):
        self.a.fill(7)
        for i0 in range(2):
            for i1 in range(3):
                for i2 in range(3):
                    self.assertEqual(self.a[i0,i1,i2], 7)

    def test_resize_equal(self):

        expected_a = np.zeros( (2*3*4,) )
        i = 0
        for i0 in range(2):
            for i1 in range(3):
                for i2 in range(4):
                    val = i0*100 + i1*10 + i2
                    expected_a[i] = val
                    i += 1
        expected_a = expected_a.reshape( (4,2,3) )

        self.a.resize(4,2,3)

        for i0 in range(4):
            for i1 in range(2):
                for i2 in range(3):
                    self.assertEqual(self.a[i0,i1,i2], expected_a[i0,i1,i2])

        self.assertEqual(self.a.n0(), 4)
        self.assertEqual(self.a.n1(), 2)
        self.assertEqual(self.a.n2(), 3)
        self.assertEqual(self.a.dim(0), 4)
        self.assertEqual(self.a.dim(1), 2)
        self.assertEqual(self.a.dim(2), 3)
        self.assertEqual(self.a.size(), 24)

    def test_resize_less(self):

        self.a.resize(3,2,1)

        self.assertEqual(self.a[0,0,0], 0.)
        self.assertEqual(self.a[0,1,0], 1.)
        self.assertEqual(self.a[1,0,0], 2.)
        self.assertEqual(self.a[1,1,0], 3.)
        self.assertEqual(self.a[2,0,0], 10.)
        self.assertEqual(self.a[2,1,0], 11.)

        self.assertEqual(self.a.n0(), 3)
        self.assertEqual(self.a.n1(), 2)
        self.assertEqual(self.a.n2(), 1)
        self.assertEqual(self.a.dim(0), 3)
        self.assertEqual(self.a.dim(1), 2)
        self.assertEqual(self.a.dim(2), 1)
        self.assertEqual(self.a.size(), 6)

    def test_resize_greater(self):

        expected_a = np.zeros( (3*4*5,) )
        i = 0
        for i0 in range(2):
            for i1 in range(3):
                for i2 in range(4):
                    val = i0*100 + i1*10 + i2
                    expected_a[i] = val
                    i += 1

        expected_a = expected_a.reshape( (3,4,5) )

        self.a.resize(3,4,5)

        for i0 in range(3):
            for i1 in range(4):
                for i2 in range(5):
                    self.assertEqual(self.a[i0,i1,i2], expected_a[i0,i1,i2])

        self.assertEqual(self.a.n0(), 3)
        self.assertEqual(self.a.n1(), 4)
        self.assertEqual(self.a.n2(), 5)
        self.assertEqual(self.a.dim(0), 3)
        self.assertEqual(self.a.dim(1), 4)
        self.assertEqual(self.a.dim(2), 5)
        self.assertEqual(self.a.size(), 60)

    def test_reallocate(self):
        self.assertRaises(RuntimeError,self.a.allocate,4,4,4)

class TestArray3DAllocateConstructor(unittest.TestCase, TestArray3DBase):
    """Test Array3D allocated in constructor"""

    def setUp(self):
        self.a = DoubleArray3D(2,3,4)
        f = Array3DComputeTestValue()
        self.a.fill(f)

class TestArray3DAllocateMethod(unittest.TestCase, TestArray3DBase):
    """Test Array3D allocated in constructor method"""

    def setUp(self):
        self.a = DoubleArray3D()
        self.a.allocate(2,3,4)
        f = Array3DComputeTestValue()
        self.a.fill(f)

class TestArray3DNotAllocated(unittest.TestCase):

    def setUp(self):
        self.a = DoubleArray3D()

    def test_str(self):
        expected_re = "<Array3D not allocated>"
        s = '%s' % self.a
        self.assertRegexpMatches(s, expected_re)

    def test_getitem(self):
        self.assertRaises(RuntimeError,self.a.__getitem__,(0,0))

    def test_size(self):
        self.assertEqual(self.a.n0(), 0)
        self.assertEqual(self.a.n1(), 0)
        self.assertEqual(self.a.n2(), 0)
        self.assertEqual(self.a.dim(0), 0)
        self.assertEqual(self.a.dim(1), 0)
        self.assertEqual(self.a.dim(2), 0)
        self.assertEqual(self.a.size(), 0)

    def test_fill(self):
        self.assertRaises(RuntimeError,self.a.fill,7)

    def test_resize(self):
        self.assertRaises(RuntimeError,self.a.resize,4,8,12)

if __name__ == '__main__':
    unittest.main()
