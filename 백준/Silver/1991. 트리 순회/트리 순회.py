N = int(input())

def preorder_traversal(tree, node, checked):
  checked[node] = True # 방문 처리 후 출력
  print(node, end='')
  if tree[node][0] != '.': #왼쪽 노드가 비어있지 않다면 함수 호출
    preorder_traversal(tree, tree[node][0], checked)
  if tree[node][1] != '.': #오른쪽 노드가 비어있지 않다면 함수 호출
    preorder_traversal(tree, tree[node][1], checked)

def inorder_traversal(tree, node, checked):
  if tree[node][0] != '.': #왼쪽 노드가 비어있지 않다면 함수 호출
    inorder_traversal(tree, tree[node][0], checked)
  checked[node] = True # 방문 처리 후 출력
  print(node, end='')
  if tree[node][1] != '.': #오른쪽 노드가 비어있지 않다면 함수 호출
    inorder_traversal(tree, tree[node][1], checked)

def postorder_traversal(tree, node, checked):
  if tree[node][0] != '.': #왼쪽 노드가 비어있지 않다면 함수 호출
    postorder_traversal(tree, tree[node][0], checked)
  if tree[node][1] != '.': #오른쪽 노드가 비어있지 않다면 함수 호출
    postorder_traversal(tree, tree[node][1], checked)
  checked[node] = True # 방문 처리 후 출력
  print(node, end='')

tree = {}
checked = {}
for _ in range(N):
  node, left, right = input().split()
  tree[node] = [left, right]
  checked[node] = False

preorder_traversal(tree, 'A', checked)
print()
inorder_traversal(tree, 'A', checked)
print()
postorder_traversal(tree, 'A', checked)