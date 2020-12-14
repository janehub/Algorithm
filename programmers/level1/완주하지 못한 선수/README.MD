<h1><a href="https://programmers.co.kr/learn/courses/30/lessons/42576">완주하지 못한 선수</a></h1>

<h6>문제 설명</h6>
<p>수많은 마라톤 선수들이 마라톤에 참여하였습니다. 단 한 명의 선수를 제외하고는 모든 선수가 마라톤을 완주하였습니다.</p>

<p>마라톤에 참여한 선수들의 이름이 담긴 배열 participant와 완주한 선수들의 이름이 담긴 배열 completion이 주어질 때, 완주하지 못한 선수의 이름을 return 하도록 solution 함수를 작성해주세요.</p>

<h5>제한사항</h5>

<ul>
<li>마라톤 경기에 참여한 선수의 수는 1명 이상 100,000명 이하입니다.</li>
<li>completion의 길이는 participant의 길이보다 1 작습니다.</li>
<li>참가자의 이름은 1개 이상 20개 이하의 알파벳 소문자로 이루어져 있습니다.</li>
<li>참가자 중에는 동명이인이 있을 수 있습니다.</li>
</ul>

<h5>입출력 예</h5>
<table class="table">
        <thead><tr>
<th>participant</th>
<th>completion</th>
<th>return</th>
</tr>
</thead>
        <tbody><tr>
<td>[<q>leo</q>, <q>kiki</q>, <q>eden</q>]</td>
<td>[<q>eden</q>, <q>kiki</q>]</td>
<td><q>leo</q></td>
</tr>
<tr>
<td>[<q>marina</q>, <q>josipa</q>, <q>nikola</q>, <q>vinko</q>, <q>filipa</q>]</td>
<td>[<q>josipa</q>, <q>filipa</q>, <q>marina</q>, <q>nikola</q>]</td>
<td><q>vinko</q></td>
</tr>
<tr>
<td>[<q>mislav</q>, <q>stanko</q>, <q>mislav</q>, <q>ana</q>]</td>
<td>[<q>stanko</q>, <q>ana</q>, <q>mislav</q>]</td>
<td><q>mislav</q></td>
</tr>
</tbody>
      </table>
<h5>입출력 예 설명</h5>

<p>예제 #1<br>
<q>leo</q>는 참여자 명단에는 있지만, 완주자 명단에는 없기 때문에 완주하지 못했습니다.</p>

<p>예제 #2<br>
<q>vinko</q>는 참여자 명단에는 있지만, 완주자 명단에는 없기 때문에 완주하지 못했습니다.</p>

<p>예제 #3<br>
<q>mislav</q>는 참여자 명단에는 두 명이 있지만, 완주자 명단에는 한 명밖에 없기 때문에 한명은 완주하지 못했습니다.</p>
