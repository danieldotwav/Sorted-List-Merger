# Sorted List Merger - C++ Implementation

## Introduction
This C++ project demonstrates the merging of two sorted linked lists into a single sorted list by splicing together the nodes of the first two lists.

## Features
- Efficient merging of two sorted linked lists
- Utilization of existing nodes without creating new ones
- Maintains the order and integrity of the original lists

## How It Works
The `mergeTwoLists` function compares the values at the head of each list and appends the lower value to the merged list, advancing the pointer in the list from which the value was taken. This process continues until both lists are fully traversed.

### Complexity Analysis
- **Time Complexity:** O(n+m), where n and m are the lengths of the two lists.
- **Space Complexity:** O(1), as it reuses existing nodes.

## Usage
The repository includes support functions like `createLinkedList`, `deleteLinkedList`, and `printList` for list operations.

### Function Descriptions
- `createLinkedList`: Creates a linked list from a vector of integers.
- `deleteLinkedList`: Safely deletes a linked list, freeing memory.
- `printList`: Outputs the elements of a linked list.

## Code Snippet
```cpp
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
	// Handle Empty Lists
	if (list1 == nullptr && list2 == nullptr) { return nullptr; }
	// If one list is empty, return the other
	if (list1 == nullptr) { return list2; }
	if (list2 == nullptr) { return list1; }

	// Create a new list to represent merged list
	ListNode* head = nullptr;

	if (list1->val <= list2->val) {
		head = list1;
		list1 = list1->next;
	}
	else {
		head = list2;
		list2 = list2->next;
	}

	ListNode* dummyHead = head;

	// Loop through both lists and compare values
	while (list1 != nullptr && list2 != nullptr) {
		if (list1->val <= list2->val) {
			dummyHead->next = list1;
			list1 = list1->next;
		}
		else {
			dummyHead->next = list2;
			list2 = list2->next;
		}
		dummyHead = dummyHead->next;
	}

	// Directly link the remainder of the non-empty list
	dummyHead->next = (list1 != nullptr) ? list1 : list2;

	return head;
}
```

## Test Cases
Test cases cover various scenarios including:
- Both lists of equal length
- One list longer than the other
- One or both lists empty
- Lists with interleaving or identical values
- Lists with one element each
