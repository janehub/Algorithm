<h1><a href="https://programmers.co.kr/learn/courses/30/lessons/12909">올바른 괄호</a></h1>

<h6>문제 설명</h6>
<p>괄호가 바르게 짝지어졌다는 것은 &#39;(&#39; 문자로 열렸으면 반드시 짝지어서 &#39;)&#39; 문자로 닫혀야 한다는 뜻입니다. 예를 들어</p>

<ul>
<li><q>()()</q> 또는 <q>(())()</q> 는 올바른 괄호입니다.</li>
<li><q>)()(</q> 또는 <q>(()(</q> 는 올바르지 않은 괄호입니다.</li>
</ul>

<p>&#39;(&#39; 또는 &#39;)&#39; 로만 이루어진 문자열 s가 주어졌을 때, 문자열 s가 올바른 괄호이면 true를 return 하고, 올바르지 않은 괄호이면 false를 return 하는 solution 함수를 완성해 주세요.</p>

<h5>제한사항</h5>

<ul>
<li>문자열 s의 길이 : 100,000 이하의 자연수</li>
<li>문자열 s는 &#39;(&#39; 또는 &#39;)&#39; 로만 이루어져 있습니다.</li>
</ul>

<hr>

<h5>입출력 예</h5>
<table class="table">
        <thead><tr>
<th>s</th>
<th>answer</th>
</tr>
</thead>
        <tbody><tr>
<td><q>()()</q></td>
<td>true</td>
</tr>
<tr>
<td><q>(())()</q></td>
<td>true</td>
</tr>
<tr>
<td><q>)()(</q></td>
<td>false</td>
</tr>
<tr>
<td><q>(()(</q></td>
<td>false</td>
</tr>
</tbody>
      </table>
<h5>입출력 예 설명</h5>

<p>입출력 예 #1,2,3,4<br>
문제의 예시와 같습니다.</p>
