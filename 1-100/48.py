class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        new_matrix =[[0]*len(matrix) for _ in range(len(matrix))]
        for col,col_val in enumerate(matrix):
            for row,row_val in enumerate(matrix[col]):
                new_matrix[row][-col-1] = matrix[col][row]
        for col,col_val in enumerate(new_matrix):
            for row, row_val in enumerate(new_matrix[col]):
                matrix[col][row] = new_matrix[col][row]
        return matrix