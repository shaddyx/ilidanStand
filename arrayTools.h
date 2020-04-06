/*
 * arrayTools.h
 *
 *  Created on: Mar 29, 2020
 *      Author: shaddy
 */

#ifndef ARRAYTOOLS_H_
#define ARRAYTOOLS_H_


#define array_size(a)                               \
  ((sizeof(a) / sizeof(*(a))) /                     \
  static_cast<size_t>(!(sizeof(a) % sizeof(*(a)))))


#endif /* ARRAYTOOLS_H_ */
