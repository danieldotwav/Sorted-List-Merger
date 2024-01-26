// You are given the heads of two sorted linked lists list1 and list2.
// Merge the two lists into one sorted list.The list should be made by splicing together the nodes of the first two lists.
// Return the head of the merged linked list.

// Assuming the existence of createLinkedList, printList, and deleteLinkedList functions

#include <iostream>
#include <vector>
#include "ListNode.h";
using namespace std;

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);

ListNode* createLinkedList(const vector<int>& values);
void deleteLinkedList(ListNode* head);
void printList(ListNode* head);

int main() {

	// Test Case 1: Both Lists Are Non-Empty and of Equal Length
	ListNode* list1 = createLinkedList(vector<int> {1, 3, 5, 7});
	ListNode* list2 = createLinkedList(vector<int> {2, 4, 6, 8});
	ListNode* mergedList = mergeTwoLists(list1, list2);
	printList(mergedList);
	deleteLinkedList(mergedList);

	// Test Case 2: First List Is Longer Than Second
	list1 = createLinkedList(vector<int> {1, 3, 5, 7, 9});
	list2 = createLinkedList(vector<int> {2, 4, 6});
	mergedList = mergeTwoLists(list1, list2);
	printList(mergedList);
	deleteLinkedList(mergedList);

	// Test Case 3: Second List Is Longer Than First
	list1 = createLinkedList(vector<int> {1, 3, 5});
	list2 = createLinkedList(vector<int> {2, 4, 6, 8, 10});
	mergedList = mergeTwoLists(list1, list2);
	printList(mergedList);
	deleteLinkedList(mergedList);

	// Test Case 4: First List Is Empty
	list1 = createLinkedList(vector<int> {});
	list2 = createLinkedList(vector<int> {1, 2, 3, 4});
	mergedList = mergeTwoLists(list1, list2);
	printList(mergedList);
	deleteLinkedList(mergedList);

	// Test Case 5: Second List Is Empty
	list1 = createLinkedList(vector<int> {1, 2, 3, 4});
	list2 = createLinkedList(vector<int> {});
	mergedList = mergeTwoLists(list1, list2);
	printList(mergedList);
	deleteLinkedList(mergedList);

	// Test Case 6: Both Lists Are Empty
	list1 = createLinkedList(vector<int> {});
	list2 = createLinkedList(vector<int> {});
	mergedList = mergeTwoLists(list1, list2);
	printList(mergedList);
	deleteLinkedList(mergedList);

	// Test Case 7: Lists With Interleaving Values
	list1 = createLinkedList(vector<int> {1, 4, 5});
	list2 = createLinkedList(vector<int> {2, 3, 6});
	mergedList = mergeTwoLists(list1, list2);
	printList(mergedList);
	deleteLinkedList(mergedList);

	// Test Case 8: Lists With Identical Values
	list1 = createLinkedList(vector<int> {1, 1, 1});
	list2 = createLinkedList(vector<int> {1, 1, 1});
	mergedList = mergeTwoLists(list1, list2);
	printList(mergedList);
	deleteLinkedList(mergedList);

	// Test Case 9: Lists With One Element Each
	list1 = createLinkedList(vector<int> {1});
	list2 = createLinkedList(vector<int> {2});
	mergedList = mergeTwoLists(list1, list2);
	printList(mergedList);
	deleteLinkedList(mergedList);

	return 0;
}

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

ListNode* createLinkedList(const vector<int>& values) {
	if (values.empty()) { return nullptr; }

	ListNode* head = new ListNode(values[0]);
	ListNode* current = head;

	for (int i = 1; i < values.size(); ++i) {
		current->next = new ListNode(values[i]);
		current = current->next;
	}

	return head;
}

void deleteLinkedList(ListNode* head) {
	while (head != nullptr) {
		ListNode* temp = head;
		head = head->next;
		delete temp;
	}
}

void printList(ListNode* head) {
	int count = 0;
	cout << "[";
	while (head != nullptr) {
		if (count == 0) {
			cout << head->val;
			head = head->next;
			++count;
		}
		else {
			cout << ", " << head->val;
			head = head->next;
		}
	}
	cout << "]\n\n";
}
