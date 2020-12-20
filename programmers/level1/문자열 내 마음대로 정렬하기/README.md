<h1><a href="https://programmers.co.kr/learn/courses/30/lessons/12915">문자열 내 마음대로 정렬하기</a></h1>

<h6>문제 설명</h6>
><p>문자열로 구성된 리스트 strings와, 정수 n이 주어졌을 때, 각 문자열의 인덱스 n번째 글자를 기준으로 오름차순 정렬하려 합니다. 예를 들어 strings가 [<q>sun</q>, <q>bed</q>, <q>car</q>]이고 n이 1이면 각 단어의 인덱스 1의 문자 <q>u</q>, <q>e</q>, <q>a</q>로 strings를 정렬합니다.</p>

<h5>제한 조건</h5>

<ul>
<li>strings는 길이 1 이상, 50이하인 배열입니다.</li>
<li>strings의 원소는 소문자 알파벳으로 이루어져 있습니다.</li>
<li>strings의 원소는 길이 1 이상, 100이하인 문자열입니다.</li>
<li>모든 strings의 원소의 길이는 n보다 큽니다.</li>
<li>인덱스 1의 문자가 같은 문자열이 여럿 일 경우, 사전순으로 앞선 문자열이 앞쪽에 위치합니다.</li>
</ul>

<h5>입출력 예</h5>
<table class="table">
        <thead><tr>
<th>strings</th>
<th>n</th>
<th>return</th>
</tr>
</thead>
        <tbody><tr>
<td>[<q>sun</q>, <q>bed</q>, <q>car</q>]</td>
<td>1</td>
<td>[<q>car</q>, <q>bed</q>, <q>sun</q>]</td>
</tr>
<tr>
<td>[<q>abce</q>, <q>abcd</q>, <q>cdx</q>]</td>
<td>2</td>
<td>[<q>abcd</q>, <q>abce</q>, <q>cdx</q>]</td>
</tr>
</tbody>
      </table>
<h5>입출력 예 설명</h5>

<p><strong>입출력 예 1</strong><br>
<q>sun</q>, <q>bed</q>, <q>car</q>의 1번째 인덱스 값은 각각 <q>u</q>, <q>e</q>, <q>a</q> 입니다. 이를 기준으로 strings를 정렬하면 [<q>car</q>, <q>bed</q>, <q>sun</q>] 입니다.</p>

<p><strong>입출력 예 2</strong><br>
<q>abce</q>와 <q>abcd</q>, <q>cdx</q>의 2번째 인덱스 값은 <q>c</q>, <q>c</q>, <q>x</q>입니다. 따라서 정렬 후에는 <q>cdx</q>가 가장 뒤에 위치합니다. <q>abce</q>와 <q>abcd</q>는 사전순으로 정렬하면 <q>abcd</q>가 우선하므로, 답은 [<q>abcd</q>, <q>abce</q>, <q>cdx</q>] 입니다.</p>
