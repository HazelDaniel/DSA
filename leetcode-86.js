function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}
/**
 * @param {ListNode} head
 * @param {number} x
 * @return {ListNode}
 */
var partition = function (head, x) {
  let positionDetails = findPosition(head, x);
  let prevNode = null;

  if (positionDetails.length === 2) {
    let [curr, index] = positionDetails;
    while (curr) {
      if (curr.val < x) {
        moveBefore(head, index, curr, prevNode);
        quickSortLinkedListRange(head, 0, index - 1);
      }
      prevNode = curr;
      curr = curr.next;
    }
  }
};

function moveBefore(head, index, node, prevNode) {
  let curr = head;
  let prev = null;
  let currIndex = 0;

  while (currIndex < index) {
    if (prev && prev.val <= curr.val) {
      if (prevNode) prevNode.next = node.next;
      prev.next = node;
      node.next = curr;
    } else if (prev.val <= curr.val) {
      node.next = curr;
      head = node;
    }
    prev = curr;
    curr = curr.next;
  }
  return head;
}

function findPosition(head, target) {
  curr = head;
  let position = 0;
  const positionDetails = [];

  while (curr) {
    if (curr.val === target) {
      positionDetails.push(curr, position);
      return positionDetails;
    }
    curr = curr.next;
    position++;
  }
  return positionDetails;
}


function quickSortLinkedListRange(head, start, end) {
  if (!head || start >= end) {
    // Base case: If the list is empty or the range is invalid, it is already sorted.
    return head;
  }

  // Find the pivot and its index
  let pivotIndex = partitionListRange(head, start, end);
  let pivot = getNodeAtIndex(head, pivotIndex);

  // Recursively sort the partitions
  head = quickSortLinkedListRange(head, start, pivotIndex - 1);
  head = quickSortLinkedListRange(head, pivotIndex + 1, end);

  return head;
}

function partitionListRange(head, start, end) {
  // Move to the start position
  let current = head;
  for (let i = 0; i < start && current; i++) {
    current = current.next;
  }

  // Choose a pivot (e.g., the element at the end of the range)
  let pivot = current;
  let pivotIndex = start;

  // Perform partitioning
  for (let i = start; i < end; i++) {
    if (current && current.next) {
      current = current.next;
    }
    if (current && current.val < pivot.val) {
      pivotIndex++;
      // Swap vals
      let temp = current.val;
      current.val = getNodeAtIndex(head, pivotIndex).val;
      getNodeAtIndex(head, pivotIndex).val = temp;
    }
  }

  // Swap pivot with the element at pivotIndex
  let temp = pivot.val;
  pivot.val = getNodeAtIndex(head, pivotIndex).val;
  getNodeAtIndex(head, pivotIndex).val = temp;

  return pivotIndex;
}

function getNodeAtIndex(head, index) {
  let current = head;
  for (let i = 0; i < index && current; i++) {
    current = current.next;
  }
  return current;
}