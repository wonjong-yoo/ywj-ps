#include <vector>
#include <iostream>

using namespace std;

int cardIndex = 0;

const int BLACKJACK = 21;

const int UNKNOWN_DEALER_CARD_INDEX = 0;

// 내림차순 정렬 
bool isBlackJack(vector<int>& cards) {
  // 일단 1은 1로 계산하고 뒤에서 판단한다.
  vector<int> oneIndexes;

  int sum = 0;
  for (int i = 0; i < cards.size(); i++) {
    if (cards[i] == 1) {
      oneIndexes.push_back(i);
    }
    // 11, 12, 13은 10으로 치환
    if (cards[i] == 11 || cards[i] == 12 || cards[i] == 13) {
      sum += 10;
    }
    sum += cards[i];
  }

  if (oneIndexes.empty()) {
    return sum == BLACKJACK;
  }
  // 1이 존재한다면 최대한 BlackJack 에 맞도록 수정한다.
  sum -= oneIndexes.size();
  

  for (int i = 0; i < oneIndexes.size(); i++) {
    int tempSum = sum;
    for (int one = i; one > 0; one--) {
      tempSum += 1;
    }
    for (int eleven = oneIndexes.size() - i; eleven > 0; eleven--) {
      tempSum += 11;
    }
      cout << "tempsum : " << tempSum << endl;
    if (tempSum == BLACKJACK) return true;
  }

  return false;
}

int answer = 0;

// X이상 Y미만
// Y 초과하면 -1 리턴, 그외 최대 합 리턴
int getSumAndGreaterThanY(vector<int>& cards, int y) {
  // 일단 1은 1로 계산하고 뒤에서 판단한다.
  vector<int> oneIndexes;

  int sum = 0;
  for (int i = 0; i < cards.size(); i++) {
    if (cards[i] == 1) {
      oneIndexes.push_back(i);
    }
    // 11, 12, 13은 10으로 치환
    if (cards[i] == 11 || cards[i] == 12 || cards[i] == 13) {
      sum += 10;
    }
    cout << "cards[i] : " << cards[i] << endl;
    sum += cards[i];
  }

  if (oneIndexes.empty()) {
    if (sum > y) {
      return -1;
    }
  }
  sum -= oneIndexes.size();
  
  for (int i = 0; i < oneIndexes.size(); i++) {
    int tempSum = sum;
    for (int one = i; one > 0; one--) {
      
      tempSum += 1;
    }
    for (int eleven = oneIndexes.size() - i; eleven > 0; eleven--) {
      tempSum += 11;
    }
    if (tempSum > y) {
      continue;
    } else {
      if (sum < tempSum) {
        sum = tempSum;
      }
    }
  }

  return sum;
}

void startBlackjack(vector<int>& cards) {
  vector<int> playerCards;
  vector<int> dealerCards;
  
  // 1. 딜러가 카드를 한 장 뽑아 플레이어에게 준다.
  playerCards.push_back(cards[cardIndex++]);
  // 2. 딜러가 카드를 한 장 뽑아 딜러 앞에 뒤집어 놓는다.
  dealerCards.push_back(cards[cardIndex++]);
  // 3. 딜러가 카드를 한 장 뽑아 플레이어에게 준다.
  playerCards.push_back(cards[cardIndex++]);
  // 4. 딜러가 카드를 한 장 뽑아 딜러 앞에 보이도록 놓는다.
  dealerCards.push_back(cards[cardIndex++]);

  // 5. 플레이어에게 카드를 더 받을지 말지 물어본다.
  // 5-1. 플레이어가 최초로 받은 카드 두 장의 합이 21인 경우에는 더 이상 카드를 받지 않고 딜러의 카드를 확인하여 승패를 결정한다.
  int knownDealerCardIndex = 1;
  // Player Draw Loop
  bool isGameEnded = false;
  while(1) {
    bool isPlayerBlackJack = isBlackJack(playerCards);
    bool isDealerBlackjack = isBlackJack(dealerCards);
    if (isPlayerBlackJack && isDealerBlackjack) {
      // draw
      isGameEnded = true;
      break;
    } else if (!isPlayerBlackJack && isDealerBlackjack) {
      // 딜러 블랙잭
      answer -= 2;
      isGameEnded = true;
      break;
    } else if (isPlayerBlackJack && !isDealerBlackjack) {
      // 플레이어만 블랙잭
      isGameEnded = true;
      answer += 3;
      break;
    }
    int sum = getSumAndGreaterThanY(playerCards, BLACKJACK);
    if (sum == -1) {
      answer -= 2;
      isGameEnded = true;
      break;
    }
    // X-1 딜러의 보이는 카드가 1이거나 7이상인 경우 플레이어는 카드 합이 17 이상이 될 때까지 받는다.
    if (dealerCards[knownDealerCardIndex] == 1 || dealerCards[knownDealerCardIndex] >= 7) {
      // 카드 합이 17 이하이면 드로우
      if (sum < 17) {
        playerCards.push_back(cards[cardIndex++]);
        continue;
      } else {
        break;
      }
    }
    // X-2 딜러의 보이는 카드가 4, 5, 6인 경우, 플레어이는 카드를 받지 않는다.
    if (dealerCards[knownDealerCardIndex] == 4 || dealerCards[knownDealerCardIndex] == 5 || dealerCards[knownDealerCardIndex] == 6) {
      // 카드를 받지 않는다.
      break;
    }

    // X-3 딜러의 보이는 카드가 2, 3안 경우 플레이어는 카드 합이 12 이상이 될 때까지 받는다.
    if (dealerCards[knownDealerCardIndex] == 2 || dealerCards[knownDealerCardIndex] == 3) {
      if (sum < 12) {
        playerCards.push_back(cards[cardIndex++]);
        continue;
      } else {
        break;
      }
    }
  }

  if (isGameEnded == true) { 
    return;
  }

  while(1) {
    int sum = getSumAndGreaterThanY(dealerCards, BLACKJACK);
    if (sum == -1) {
      answer += 2;
      isGameEnded = true;
      break;
    }

    if (sum < 17) {
      dealerCards.push_back(cards[cardIndex++]);
    } else {
      break;
    }
  }

  if (isGameEnded == true) { 
    return;
  }

  int playerSum = getSumAndGreaterThanY(playerCards, BLACKJACK);
  int dealerSum = getSumAndGreaterThanY(dealerCards, BLACKJACK);

  if (BLACKJACK - playerSum > BLACKJACK - dealerSum) {
    answer += 2;
  } else if (BLACKJACK - playerSum == BLACKJACK - dealerSum) {
      // Do Nothing
  } else {
    answer -= 2;
  }

}

int solution(vector<int> cards) {
  while (cardIndex < cards.size()) {
    startBlackjack(cards);
  }
  return answer;
}

void blackJackUnitTest() {
  vector<int> test1 = {1, 10};
  vector<int> test2 = {1, 11};
  vector<int> test3 = {1, 12};
  vector<int> test4 = {1, 1};
  vector<int> test5 = {1, 2, 3, 4, 1};

  cout << isBlackJack(test1) << endl;
  cout << isBlackJack(test2) << endl;
  cout << isBlackJack(test3) << endl;
  cout << isBlackJack(test4) << endl;
  cout << isBlackJack(test5) << endl;
}

void isGreatThanEqualUnitTest() {
  vector<int> test1 = {10, 12};
  vector<int> test2 = {1, 10};

  cout << getSumAndGreaterThanY(test1, BLACKJACK) << endl;
  cout << getSumAndGreaterThanY(test2, BLACKJACK) << endl;
}

int main() {
  // vector<int> cards1 = {12, 7, 11, 6, 2, 12};
  // solution(cards1);
  // cout << answer << endl;

  isGreatThanEqualUnitTest();
}