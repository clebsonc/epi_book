#include <iostream>
#include <vector>
#include <algorithm>

int compFishermanDistance(std::vector<std::vector<int>> & mDist, 
                const std::vector<std::vector<int>> & mFish, int row, int col){
  if (row == 0 && col == 0){
    mDist.at(row).at(col) = mFish.at(row).at(col);
  }
  else if (row == 0){
    int left = compFishermanDistance(mDist, mFish, row, col-1);
    mDist.at(row).at(col) = left + mFish.at(row).at(col);
  }
  else if (col == 0){
    int up = compFishermanDistance(mDist, mFish, row - 1, col);
    mDist.at(row).at(col) = up + mFish.at(row).at(col);
  }
  else if (mDist.at(row).at(col) == -1){
    int up = compFishermanDistance(mDist, mFish, row-1, col);
    int left = compFishermanDistance(mDist, mFish, row, col-1);
    mDist.at(row).at(col) = mFish.at(row).at(col) + std::max(up, left);
  }
  return mDist.at(row).at(col);
}

void printMatrix(const std::vector<std::vector<int>> & fishMatrix){
  for (int i = 0; i < fishMatrix.size(); i++){
    for (int j = 0; j < fishMatrix.at(i).size(); j++){
      std::cout << fishMatrix.at(i).at(j) << "\t";
    }
    std::cout << std::endl;
  }
}

int fisherManDistance(const std::vector<std::vector<int>> & fishValues){
  int row = fishValues.size();
  int col = fishValues.at(0).size();
  std::vector<std::vector<int>> mDistance(row, std::vector<int>(col, -1));
  int distance = compFishermanDistance(mDistance, fishValues, row-1, col-1);
  printMatrix(fishValues);
  std::cout << std::endl;
  printMatrix(mDistance);
  return distance;
}



int main(){
  // Test case matrix of fish
  std::vector<std::vector<int>> fish(5, std::vector<int>(5, 0));
  fish.at(0).at(2) = 1;
  fish.at(0).at(3) = 2;
  fish.at(1).at(1) = 2;
  fish.at(1).at(2) = 4;
  fish.at(1).at(4) = 1;
  fish.at(2).at(1) = 1;
  fish.at(2).at(2) = 3;
  fish.at(2).at(3) = 1;
  fish.at(2).at(4) = 3;
  fish.at(3).at(0) = 4;
  fish.at(3).at(2) = 2;
  fish.at(3).at(4) = 4;
  fish.at(4).at(0) = 2;
  fish.at(4).at(1) = 3;
  fish.at(4).at(2) = 1;
  fish.at(4).at(4) = 4;

  std::cout << "Distance: " << fisherManDistance(fish) << std::endl;

  return 0;
}
