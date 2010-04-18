/**
 * \file    AWGQueue.h
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
 * The AWGQueue class represents a queue of items
 */

#ifndef __AWGQUEUE_H__
#define	__AWGQUEUE_H__

#include "AWGVector.h"

/**
 * \brief Default size of an AWGQueue storage
 */
#define __DEFAULT_SIZE__	10

template <class Type>
/**
 * \class AWGQueue AWGQueue.h "AWGQueue.h"
 * \brief AWGQueue represents a queue
 *
 * Class is made up of an array and two indexes.
 *
 * \see AWGVector
 */
class AWGQueue
{
private:
	AWGVector<Type> m_typeVector; /** < Storage for items */

	int m_iFront;	/** < Index of the front item */
	int m_iBack;	/** < Index of the back item */

	int m_iSize;	/** < Number of items in the AWGQueue */

	/**
	 * Doubles the size of the vector so that there is room for more elements
	 */
	void DoubleVector();

public:
	/**
	 * Default Constructor
	 */
    AWGQueue();
    
    /**
	 * Copy Constructor
	 *
	 * \param[in] orig AWGVector to copy
	 */
    AWGQueue(const AWGQueue& orig);

    /**
	 * Destructor
	 */
    virtual ~AWGQueue();

    /**
     * Gets the first item in the AWGQueue
     *
     * \return the first item in the AWGQueue
     */
    const Type &GetFront() const;

    /**
     * Checks if the AWGQueue is empty
     *
     * \return true if the AWGQueue is empty
     */
    bool IsEmpty() const;

    /**
     * Gets the number of items in the AWGQueue
     *
     * \return number of items in the AWGQueue
     */
    int GetSize() const;

    /**
     * Adds a new item at the end of the AWGQueue
     */
    void EnQueue(const Type &tItem);

    /**
     * Removes the first item in the AWGQueue
     */
    void DeQueue();

    /**
	 * Removes the first item in the AWGQueue and allows it to be saved
	 *
	 * \param[out] tItem first item
	 */
    void Dequeue(Type & tItem);

    /**
     * Empties the AWGQueue
     */
    void MakeEmpty();

    /**
     * Assignment Operator
     *
     * \param[in] orig The original AWGQueue to Copy
     * \return Reference to the current instance
     */
    const AWGQueue<Type> &operator = (const AWGQueue<Type> &orig);
};

#include "AWGQueue.cpp"

#endif	// __AWGQUEUE_H__

