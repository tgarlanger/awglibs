/**
 * \file    main.cpp
 * \author  Tony Garlanger <tgarlanger@gmail.com>
 * \version 1.0
 * \date    Sat Nov  14 10:18 2009
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
 * The main function.
 */

#include <stdio.h>

//#include "AWGVector.h"
#include "AWGClasses.h"

//template class AWGVector<int>;

/**
 * The main procedure.
 *
 * \param argv the command line
 * \param argc the number of options in the command line
 * \return return code
 * \author Tony Garlanger
 */
int main(int argc, char** argv)
{
    AWGVector<int> vec1;
    AWGVector<int> vec2(5);
    AWGVector<int> vec3(5,0);

    int i;

    vec1.SetSize(3);

    /*
     * vec 1:
     * index: 0  value: 0
     * index: 1  value: 1
     * index: 2  value: 2
     */
    printf("vec 1:\n");
    for (i=0; i < vec1.GetSize(); i++)
    {
        vec1[i] = i;
        printf("index: %d  value: %d\n",i,vec1[i]);
    }

    /*
     * vec 2:
     * index: 0  value: 0
     * index: 1  value: 5
     * index: 2  value: 10
     * index: 3  value: 15
     * index: 4  value: 20
     */
    printf("\n\nvec 2:\n");
    for (i=0; i < vec2.GetSize(); i++)
    {
        vec2[i] = i*vec2.GetSize();
        printf("index: %d  value: %d\n",i,vec2[i]);
    }

    /*
     * vec 3:
     * index: 1  value: 0
     * index: 2  value: 0
     * index: 3  value: 0
     * index: 4  value: 0
     * index: 5  value: 0
     */
    printf("\n\nvec 3:\n");
    for (i=0; i < vec3.GetSize(); i++ )
    {
        printf("index: %d  value: %d\n",i,vec3[i]);
    }

    return (0);
}

