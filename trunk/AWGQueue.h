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
 * The AWGQueue class represents a queue of items
 */

#ifndef __AWGQUEUE_H__
#define	__AWGQUEUE_H__

#include "AWGVector.h"

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

public:
    AWGQueue();
    
    AWGQueue(const AWGQueue& orig);

    virtual ~AWGQueue();

    const Type &GetFront() const;

    bool IsEmpty() const;

    int GetSize() const;

    void EnQueue(const Type &tItem);

    void DeQueue();

    void Dequeue(Type &tItem);

    void MakeEmpty();
};

#endif	// __AWGQUEUE_H__

