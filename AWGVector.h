/**
 * \file    AWGVector.h
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

#ifndef __AWGVECTOR_H__
#define __AWGVECTOR_H__

template <class Type>
/**
 * \class AWGVector AWGVector.h "AWGVector.h"
 * \brief AWGVector represents a 1-dimensional array
 *
 * Class is made up of an array of type Type and a size
 */
class AWGVector
{
private:
    int m_iSize;  /**< size of the AWGVector */
    Type *m_typeVector;     /**< array of Type items */
public:
    /**
     * Default Constructor
     */
    AWGVector();

    /**
     * Copy Constructor
     *
     * \param[in] orig AWGVector to copy
     */
    AWGVector(const AWGVector& orig);
    
    /**
     * Parameterized Constructor
     * 
     * \param[in] iSize value to set the size to
     */
    AWGVector(int iSize);
    
    /**
     * Parameterized Constructor
     * 
     * \param[in] iSize value to set the size to
     * \param[in] typeDefaultValue value to set the items in the array to
     */
    AWGVector(int iSize, Type typeDefaultValue);

    /**
     * Destructor
     */
    virtual ~AWGVector();

    /**
     * Array subscript operator
     *
     * \param[in] iIndex index in the vector to return
     * \return Type object at index iIndex
     */
    Type & operator [] (const int iIndex);

    /**
     * Array subscript operator
     *
     * \param[in] iIndex index in the vector to return
     * \return Type object at index iIndex
     */
    const Type &operator [] (const int iIndex) const;

    /**
     * Assignment operator
     *
     * \param[in] orig The original AWGVector to copy
     * \return Reference to current instance
     */
    const AWGVector<Type> &operator = (const AWGVector<Type> &orig);

    /**
     * Gets the current size of the AWGVector
     *
     * \return size of the AWGVector
     */
    int GetSize();

    /**
     * Changes the size of the AWGVector
     *
     * \param[in] iSize value to resize to
     * \return nothing
     */
    void SetSize(int iSize);
};

#include "AWGVector.cpp"

#endif  //__AWGVECTOR_H__
