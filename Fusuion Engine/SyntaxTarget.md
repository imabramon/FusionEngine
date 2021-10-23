# The Syntax of View2048::init() should look like this

auto currentScoreView = new CellView(... currentScore);
auto bestScoreView = new CellView(... bestScore);
auto fieldView = new FieldView(... field);

_view   += currentScoreView->setPosition(x1, y1);
_view   +=  bestScoreView->setPosition(x2, y2);
_view   += fieldView->setPosition(x3, y3); 

# The Syntax of main() should look like this

Model2048 model(...);
View2048 view(model);
Controller2048 controller(model, view);
FUSION_GAME_WITH(controller)

