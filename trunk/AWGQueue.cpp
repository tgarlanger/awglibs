/**
 * \file    AWGQueue.cpp
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

#include "AWGQueue.h"

template <class Type>
AWGQueue<Type>::AWGQueue()
	: m_iSize(0),
	  m_iFront(0),
	  m_iBack(-1),
	  m_typeVector(__DEFAULT_SIZE__)
{
}

template <class Type>
AWGQueue<Type>::AWGQueue(const AWGQueue& orig)
	: m_iSize(orig.m_iSize),
	  m_iFront(orig.m_iFront),
	  m_iBack(orig.m_iBack),
	  m_typeVector(orig.m_typeVector)
{
}

template <class Type>
AWGQueue<Type>::~AWGQueue()
{
}

template <class Type>
bool AWGQueue<Type>::IsEmpty()
{
	return m_iSize == 0;
}
