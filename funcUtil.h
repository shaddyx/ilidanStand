/*
 * funcUtil.h
 *
 *  Created on: Mar 29, 2020
 *      Author: shaddy
 */

#ifndef FUNCUTIL_H_
#define FUNCUTIL_H_


#define defineCB(returnType, name, ...) returnType (* name) (__VA_ARGS__)
#define applyCallback(cb, ...) (*cb)(__VA_ARGS__)

#endif /* FUNCUTIL_H_ */
