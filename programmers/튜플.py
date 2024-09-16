import re

def solution(s):
    # 집합 표현을 숫자들로 파싱
    sets = re.findall(r'\{([\d,]+)\}', s)
    
    # 각 집합을 리스트로 변환
    sets = [set(map(int, x.split(','))) for x in sets]
    
    # 집합을 크기 순으로 정렬
    sets.sort(key=len)
    
    answer = []
    seen = set()
    
    # 각 집합을 순서대로 확인하면서 튜플 복원
    for subset in sets:
        # 새로운 원소는 아직 seen에 없는 원소
        new_element = (subset - seen).pop()
        answer.append(new_element)
        seen.add(new_element)
    
    return answer
