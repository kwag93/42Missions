# Exam Rank 03

공부중 ..
## micro 실수
1일차

get_zone 에서 0 300 범위 체크시 단 하나라도 포함되면 아웃시켜야함 ( &&를 사용해 예외처리가 되지 않음)


in_rac 에서 뺀 값은 항상 1.f 보다 작아야한다 (x-shape->x > 1.f 로 사용하여 틀림)


draw_shapes 에서 while을 돌때 지정한 ret 의 값을 체크해야함. (fscanf 에 괄호가 넣어져 있어서 탈락)


2일차

in_rac 함수에서 shape->x + shape->width // 곱하는게 아니라 더해야한다 실수로 shape->x * shape->width

in_rac 함수에서 x - shape-> 이다. // 실수로 shape->x - x

3일 차

계산 부분에서 x -shape->x 를 shape->x - x 로 썼다 계산식좀 제대로 외우자.


## mini 실수
1일차
shapes 부분에서 값을 받을때 순차적으로 넣었는지를 확인. x y radius 순서로 넣어야한다 (x radius y 로 넣어 오류)

원의 경계인가 체크하는 부분 (shape->radius - dist > 1.f 로 해서 틀림. 1보다 작아야한다. 원의 반지름에서 빼는 것이기 때문)


2일차

if ((shape.type != 'c' && shape.type != 'C') || shape.radius <= 0.f)


radius 를 체크할때 0보다 같거나 작을 수 있음. 같다는 조건을 빼서 문제가 생겼다.

3일 차

에러메세지에 \n 을 넣어주지 않으면 에러가 발생한다
