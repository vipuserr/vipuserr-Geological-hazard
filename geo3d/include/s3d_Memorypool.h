#ifndef __MEM_POOL_H__
#define __MEM_POOL_H__


#include "s3d_KerObbtDef.h"


#define VOID void

// PI is the ratio of a circle's circumference to its diameter.
//#define PI 3.141592653589793238462643383279502884197169399375105820974944592308
/* A type used to allocate memory.  firstblock is the first block of items.  */
/*   nowblock is the block from which items are currently being allocated.   */
/*   nextitem points to the next slab of free memory for an item.            */
/*   deaditemstack is the head of a linked list (stack) of deallocated items */
/*   that can be recycled.  unallocateditems is the number of items that     */
/*   remain to be allocated from nowblock.                                   */
/* Traversal is the process of walking through the entire list of items, and */
/*   is separate from allocation.  Note that a traversal will visit items on */
/*   the "deaditemstack" stack as well as live items.  pathblock points to   */
/*   the block currently being traversed.  pathitem points to the next item  */
/*   to be traversed.  pathitemsleft is the number of items that remain to   */
/*   be traversed in pathblock.                                              */
/* alignbytes determines how new records should be aligned in memory.        */
/*   itembytes is the length of a record in bytes (after rounding up).       */
/*   itemsperblock is the number of items allocated at once in a single      */
/*   block.  itemsfirstblock is the number of items in the first block,      */
/*   which can vary from the others.  items is the number of currently       */
/*   allocated items.  maxitems is the maximum number of items that have     */
/*   been allocated at once; it is the current number of items plus the      */
/*   number of records kept on deaditemstack.                                */
/********* Memory management routines begin here                     *********/

#define NULL    0

class LIB_GMKEROBBT_EXP CMemoryPool
{
public:
	CMemoryPool();
	CMemoryPool(int, int, int, int);
	virtual ~CMemoryPool();
	/* Set all of a pool's fields to zero.                         */
	/*  This procedure should never be called on a pool that has any memory      */
	/*  allocated to it, as that memory would leak.                              */
	void Zero();

	/*  Deallocate all items in a pool.                          */
	/*  The pool is returned to its starting state, except that no memory is     */
	/*  freed to the operating system.  Rather, the previously allocated blocks  */
	/*  are ready to be reused.                                                  */
	void Restart();

	/*  Initialize a pool of memory for allocation of items.					 */
	/*  This routine initializes the machinery for allocating items.  A `pool'   */
	/*  is created whose records have size at least `bytecount'.  Items will be  */
	/*  allocated in `itemcount'-item blocks.  Each item is assumed to be a      */
	/*  collection of words, and either pointers or floating-point values are    */
	/*  assumed to be the "primary" word type.  (The "primary" word type is used */
	/*  to determine alignment of items.)  If `alignment' isn't zero, all items  */
	/*  will be `alignment'-byte aligned in memory.  `alignment' must be either  */
	/*  a multiple or a factor of the primary word size; powers of two are safe. */
	/*  `alignment' is normally used to create a few unused bits at the bottom   */
	/*  of each item's pointer, in which information may be stored.              */
	/*  Don't change this routine unless you understand it.                      */

	void Init(int bytecount, int itemcount, int firstitemcount, int alignment);
	void Deinit();		// Free to the operating system all memory taken by a pool
	VOID *Alloc();		//  Allocate space for an item
	void Dealloc(VOID *dyingitem);/* Deallocate space for an item.
								  The deallocated space is stored in a queue for later reuse. */

	void traversalinit();		/*  Prepare to traverse the entire list of items.        */
								/*  This routine is used in conjunction with traverse(). */

	/*****************************************************************************/
	/*  traverse()   Find the next item in the list.                             */
	/*  This routine is used in conjunction with traversalinit().  Be forewarned */
	/*  that this routine successively returns all items in the list, including  */
	/*  deallocated ones on the deaditemqueue.  It's up to you to figure out     */
	/*  which ones are actually dead.  Why?  I don't want to allocate extra      */
	/*  space just to demarcate dead items.  It can usually be done more         */
	/*  space-efficiently by a routine that knows something about the structure  */
	/*  of the item.                                                             */
	/*****************************************************************************/
	VOID *traverse();

	//共14个数据成员：
	VOID **m_firstblock, **m_nowblock;
	VOID *m_nextitem;
	VOID *m_deaditemstack;
	VOID **m_pathblock;
	VOID *m_pathitem;
	int m_alignbytes;
	int m_itembytes;
	int m_itemsperblock;
	int m_itemsfirstblock;
	int m_items, m_maxitems;
	int m_unallocateditems;
	int m_pathitemsleft;
};



#endif