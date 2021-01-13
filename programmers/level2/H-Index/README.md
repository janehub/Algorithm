<h1><a href="https://programmers.co.kr/learn/courses/30/lessons/42747#">H-Index</a></h1>

<h6>문제 설명</h6>
<p>H-Index는 과학자의 생산성과 영향력을 나타내는 지표입니다. 어느 과학자의 H-Index를 나타내는 값인 h를 구하려고 합니다. 위키백과<sup id="fnref1"><a href="#fn1" rel="footnote">1</a></sup>에 따르면, H-Index는 다음과 같이 구합니다.</p>

<p>어떤 과학자가 발표한 논문 <code>n</code>편 중, <code>h</code>번 이상 인용된 논문이 <code>h</code>편 이상이고 나머지 논문이 h번 이하 인용되었다면 <code>h</code>의 최댓값이 이 과학자의 H-Index입니다.</p>

<p>어떤 과학자가 발표한 논문의 인용 횟수를 담은 배열 citations가 매개변수로 주어질 때, 이 과학자의 H-Index를 return 하도록 solution 함수를 작성해주세요.</p>

<h5>제한사항</h5>

<ul>
<li>과학자가 발표한 논문의 수는 1편 이상 1,000편 이하입니다.</li>
<li>논문별 인용 횟수는 0회 이상 10,000회 이하입니다.</li>
</ul>

<h5>입출력 예</h5>
<table class="table">
        <thead><tr>
<th>citations</th>
<th>return</th>
</tr>
</thead>
        <tbody><tr>
<td>[3, 0, 6, 1, 5]</td>
<td>3</td>
</tr>
</tbody>
      </table>
<h5>입출력 예 설명</h5>

<p>이 과학자가 발표한 논문의 수는 5편이고, 그중 3편의 논문은 3회 이상 인용되었습니다. 그리고 나머지 2편의 논문은 3회 이하 인용되었기 때문에 이 과학자의 H-Index는 3입니다.</p>