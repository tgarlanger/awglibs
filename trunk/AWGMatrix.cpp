/**
 * \file    AWGMatrix.cpp
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

#include "AWGMatrix.h"

template <class Type>
AWGMatrix<Type>::AWGMatrix()
	:m_iRows(0),
	 m_iCols(0),
	 m_typeMatrix(0)
{
}

template <class Type>
AWGMatrix<Type>::AWGMatrix(const AWGMatrix& orig)
	:m_iRows(orig.GetRows()),
	 m_iCols(orig.GetCols()),
	 m_typeMatrix(orig.GetRows())
{
	for (int row = 0; row < m_iRows; row++)
	{
		m_typeMatrix[row].SetSize(m_iCols);

		for (int col = 0; col < m_iCols; col++)
		{
			m_typeMatrix[row][col] = orig[row][col];
		}
	}
}

template <class Type>
AWGMatrix<Type>::AWGMatrix(int iRows, int iCols)
	:m_iRows(iRows),
	 m_iCols(iCols),
	 m_typeMatrix(iRows)
{
	for (int row = 0; row < iRows; row++)
	{
		m_typeMatrix[row].SetSize(iCols);
	}
}

template <class Type>
AWGMatrix<Type>::AWGMatrix(int iRows, int iCols, const Type & typeDefaultValue)
{
	for (int row = 0; row < iRows; row++)
	{
		m_typeMatrix[row].SetSize(iCols);

		for (int col = 0; col < iCols; col++)
		{
			m_typeMatrix[row][col] = typeDefaultValue;
		}
	}
}

template <class Type>
AWGMatrix<Type>::~AWGMatrix()
{

}

template <class Type>
int AWGMatrix<Type>::GetRows()
{
	return m_iRows;
}

template <class Type>
int AWGMatrix<Type>::GetCols()
{
	return m_iCols;
}

template <class Type>
const AWGVector<Type> &AWGMatrix<Type>::operator[] (int iIndex) const
{
	return m_typeMatrix[iIndex];
}

template <class Type>
AWGVector<Type> &AWGMatrix<Type>::operator[] (int iIndex)
{
	return m_typeMatrix[iIndex];
}

template <class Type>
void AWGMatrix<Type>::SetSize(int iRows, int iCols)
{
	m_iRows = iRows;
	m_iCols = iCols;
	m_typeMatrix.SetSize(iRows);

	for (int row = 0; row < m_iRows; row++)
	{
		m_typeMatrix[row].SetSize(m_iCols);
	}
}

template <class Type>
void AWGMatrix<Type>::SetRows(int iRows)
{
	m_iRows = iRows;

	m_typeMatrix.SetSize(m_iRows);
}

template <class Type>
void AWGMatrix<Type>::SetCols(int iCols)
{
	m_iCols = iCols;

	for (int row = 0; row < m_iCols; row++)
	{
		m_typeMatrix[row].SetSize(m_iCols);
	}
}


