#!/usr/bin/node
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
};

function moveBefore(head, posCurr, node, prevNode) {
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


// Example usage:
let head = new ListNode(1, new ListNode(4, new ListNode(3, new ListNode(2, new ListNode(5, new ListNode(2, null))))));
console.log(partition(head, 3));
