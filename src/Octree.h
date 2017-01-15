class Octree{
  public:
    Octree(GameAsset region, List<GameAsset> objList);
  private:
    BuildTree();
    AddNode();

    GameAsset oct_region;
    List<GameAsset> objList;
};
