#include "QuickSortSuboptimal.h"

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
QuickSortSuboptimal::QuickSortSuboptimal() : QuickSorter("Quicksort Suboptimal") {}

/**
 * Destructor.
 */
QuickSortSuboptimal::~QuickSortSuboptimal() {}

/**
 * Choose a bad pivot, always the leftmost element of the subrange.
 * @param left the left index of the subrange to sort.
 * @param right the right index of the subrange to sort.
 * @return the chosen pivot value.
 */
Element& QuickSortSuboptimal::choose_pivot_strategy(const int left, const int right)
{
   return data[left];
}
