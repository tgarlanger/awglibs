/**
 * \file    AWGVector.cpp
 * \author  Tony Garlanger <tgarlanger@gmail.com>
 * \version 1.0
 * \date    Mon Nov  9 16:41:16 2009
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
 * The AWGVector class represents a 1-dimentional array
 */

#include "AWGVector.h"

#include <stdio.h>
#include <assert.h>

template <class Type>
AWGVector<Type>::AWGVector()
    : m_iSize(0)
{
    m_typeVector = NULL;

}

template <class Type>
AWGVector<Type>::AWGVector(const AWGVector& orig)
    : m_iSize(orig.GetSize())
{
    m_typeVector = new Type[m_iSize];

    for (int i = 0; i < m_iSize; i++)
    {
        m_typeVector[i] = orig[i];
    }
}

template <class Type>
AWGVector<Type>::AWGVector(int iSize)
    : m_iSize(iSize)
{
    m_typeVector = new Type[m_iSize];
}

template <class Type>
AWGVector<Type>::AWGVector(int iSize, Type typeDefaultValue)
    : m_iSize(iSize)
{
    m_typeVector = new Type[m_iSize];

    for (int i = 0; i < m_iSize; i++)
    {
        m_typeVector[i] = typeDefaultValue;
    }
}

template <class Type>
AWGVector<Type>::~AWGVector()
{
    delete[] m_typeVector;
}

template <class Type>
Type & AWGVector<Type>::operator [] (const int iIndex)
{
    if(iIndex < 0 || iIndex > m_iSize)
    {
        fprintf(stderr,"Error: bad index into array: %d",iIndex);
        assert(true);
    }

    return m_typeVector[iIndex];
}

template <class Type>
const Type &AWGVector<Type>::operator [] (const int iIndex) const
{
    if(iIndex < 0 || iIndex > m_iSize)
    {
        fprintf(stderr,"Error: bad index into array: %d",iIndex);
        assert(true);
    }

    return m_typeVector[iIndex];
}

template <class Type>
const AWGVector<Type> &AWGVector<Type>::operator = (const AWGVector<Type> &orig)
{
	delete[] m_typeVector;

	m_iSize = orig.GetSize();

	m_typeVector = new Type[m_iSize];

	for ( int index = 0; index < m_iSize; index++ )
	{
		m_typeVector[index] = orig[index];
	}
}

template <class Type>
int AWGVector<Type>::GetSize()
{
    return m_iSize;
}

template <class Type>
void AWGVector<Type>::SetSize(int iSize)
{
    if (iSize < 0)
    {
        fprintf(stderr,"Error setting size of array: %d is too small!",iSize);
        assert(true);
    }

    Type *typeTempArray = new Type[iSize];

    for (int i = 0; i < iSize && i < m_iSize; i++)
    {
        typeTempArray[i] = m_typeVector[i];
    }

    delete[] m_typeVector;

    m_typeVector = typeTempArray;

    m_iSize = iSize;
}
