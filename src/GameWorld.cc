#include "GameWorld.h"

GameWorld::GameWorld (ApplicationMode mode) {

  asset_manager = std::make_shared<GameAssetManager>(mode);

  int matrix [10][10]= {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
    {0, 0, 0, 0, 2, 0, 0, 0, 0, 0},
    {0, 0, 0, 2, 0, 0, 0, 2, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 2, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 2, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
  };
  
  for( int x= 0; x < 10; x++)
  {
    for( int z= 0; z < 10; z++)
    {
      if( matrix[x][z] == 1)
      {
            asset_manager->AddAsset(std::make_shared<CubeAsset>(-1.0 * x, 0.0, 0.0* z));
            asset_manager->AddAsset(std::make_shared<CubeAsset>(-1.0 * x, 0.0, 0.0* z));
            asset_manager->AddAsset(std::make_shared<CubeAsset>(-1.0 * x, 0.0, 0.0* z));

      }
      if( matrix[x][z] == 2)
      {
            asset_manager->AddAsset(std::make_shared<PyramidAsset>(-1.0 * x, 0.0, 0.0* z));
            asset_manager->AddAsset(std::make_shared<PyramidAsset>(-1.0 * x, 0.0, 0.0* z));
            asset_manager->AddAsset(std::make_shared<PyramidAsset>(-1.0 * x, 0.0, 0.0* z));
      }
    }
  }
}

void GameWorld::Draw() {
  asset_manager->Draw();
}

void GameWorld::UpdateCameraPosition(Input input_Direction, float MouseX, float MouseY) {
  asset_manager->UpdateCameraPosition(input_Direction, MouseX, MouseY);
}
