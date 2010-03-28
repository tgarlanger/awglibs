/**
 * \file    AWGMatrix.h
 * \author  Tony Garlanger <tgarlanger@gmail.com>
 * \version 1.0
 * \date    Sat Nov  14 16:41:16 2009
 *
 * \section LICENSE
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details at
 * http://www.gnu.org/copyleft/gpl.html
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor Boston, MA 02110-1301,  USA
 *
 * \section DESCRIPTION
 *
 * The AWGMatrix class represents a 2-dimentional array
 */

#ifndef __AWGMATRIX_H__
#define	__AWGMATRIX_H__

#include "AWGVector.h"

template <class Type>
/**
 * \class AWGMatrix AWGMatrix.h "AWGMatrix.h"
 * \brief AWGMatrix represents a 2-dimentional array
 *
 * Class is made up of an array of arrays of type Type
 *
 * \see AWGVector
 */
class AWGMatrix
{
private:
    int m_iRows; /**< number of rows */
    int m_iCols; /**< number of columns */

    /**
     * An AWGVector of AWGVectors of type 'Type' which creates a 2-dimensional
     * array
     */
    AWGVector<AWGVector <Type> > m_typeMatrix;

public:
    /**
     * Default Constructor
     */
    AWGMatrix();

    /**
     * Copy Constructor
     *
     * \param[in] orig AWGMatrix to copy
     */
    AWGMatrix(const AWGMatrix& orig);

    /**
     * Parameterized Constructor
     *
     * \param[in] iRows value to set the rows to
     * \param[in] iCols value to set the columns to
     */
    AWGMatrix(int iRows, int iCols);
    
    /**
     * Parameterized Constructor
     * 
     * \param[in] iRows value to set the rows to
     * \param[in] iCols value to set the columns to
     * \param[in] typeDefaultValue value to set the items in the matrix to
     */
    AWGMatrix(int iRows, int iCols, const Type & typeDefaultValue);

    /**
     * Destructor
     */
    virtual ~AWGMatrix();

    /**
     * Gets the current number of rows
     *
     * \return number of rows
     */
    int GetRows();

    /**
     * Gets the current number of columns
     *
     * \return number of columns
     */
    int GetCols();

    /**
     * Array Subscript Operator
     *
     * \param[in] iIndex row of the matrix to return
     * \return row of matrix at index iIndex
     */
    const AWGVector<Type> &operator[] (int iIndex) const;

    /**
     * Array Subscript Operator
     *
     * \param[in] iIndex row of the matrix to return
     * \return row of matrix at index iIndex
     */
    AWGVector<Type> &operator[] (int iIndex);

    /**
     * Changes the size of the matrix
     *
     * \param[in] iRows value to resize rows to
     * \param[in] iCols value to resize columns to
     * \return nothing
     */
    void SetSize(int iRows, int iCols);

    /**
     * Changes the number of rows
     *
     * \param[in] iRows value to resize rows to
     * \return nothing
     */
    void SetRows(int iRows);

    /**
     * Changes the number of columns
     *
     * \param[in] iCols value to resize columns to
     * \return nothing
     */
    void SetCols(int iCols);
};

#endif	// __AWGMATRIX_H__

