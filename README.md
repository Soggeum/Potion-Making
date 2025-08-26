# Potion-Making
SOLID Practice

# 실습 목표
- 객체프로그래밍의 SOLID 원칙을 준수하며 프로그래밍 해본다

# 구현 목표
<img width="898" height="321" alt="image" src="https://github.com/user-attachments/assets/8ec9b0aa-9ef2-4484-8576-51905d9b4fc8" />


- PotionRecipe 클래스를 통해 포션의 이름과 레시피를 저장
- RecipeManager를 통해 포션 레시피를 관리
- stockManager를 통해 포션의 남은 재고 관리
- AlchemyWorkshop는 RecipeManager와 stockManager를 소유하여 포션 레시피와 재고를 관리

## PotionRecipe
- 포션의 이름과 레시피를 저장
- 필요한 재료(ingredient)들을 입력받아 ingredients 배열에 하나씩 저장

## RecipeManager
- PotionRecipe를 벡터로 저장하여 레시피들을 저장
- addRecipe함수를 통해 새로운 물약의 이름과 필요한 재료들을 recipes에 저장
- getAllRecipes: 저장되어 있는 모든 레시피들을 반환
- findRecipeByName: 포션 이름을 입력 받아 해당 포션의 PotionRecipe를 반환
- findRecipeByIngredient: 재료 이름을 입력 받아 해당 재료로 만들 수 있는 포션들의 PotionRecipe를 벡터로 반환

## stockManager
- map 자료구조를 통해 potionStock에 포션의 이름과 포션의 재고수량을 저장
- initializeStock: 새로운 포션이 추가되었을 때 potionStock에 최대수량으로 저장
- getStock: 해당 포션의 재고 수량을 반환
- returnPotion: 해당 포션의 재고 수량을 최대치로 제조
- dispensePotion: 해당 포션의 재고가 남아있을 경우 1개를 소모

## AlchemyWorkshop

- RecipeManager와 stockManager를 소유하여 포션 레시피와 재고를 관리
- displayAllRecipes: 모든 포션 레시피 출력
