#!/usr/bin/env python
# Numenta Platform for Intelligent Computing (NuPIC)
#
# Copyright (C) 2014, Numenta, Inc.  All rights reserved.

"""This is a how-to for the SparseMatrix data type."""

from nupic.math import SparseMatrix


def create_sparse_matrix():
    # Create a sparse matrix
    m = SparseMatrix(
        (3, 4),
        # dtype='Float32'
    )
    return m
    # Set some values
    m.set([0, 2, 3], [1, 1, 2], [1.0, 2.0, 3.0])
    return m


if __name__ == "__main__":
    create_sparse_matrix()
