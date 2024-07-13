class Robot {
public:
    int position, health, index;
    char direction;

    Robot(int position = 0, int health = 0, char direction = 0, int index = 0)
    : position(position), health(health), direction(direction), index(index) {}
};

class Solution {
private:
    void makeCollisions(stack<Robot>& s, Robot& robot) {
        // current robot will collide with every robot in stack that is going right
        while (!s.empty() && s.top().direction == 'R' && s.top().health < robot.health) {
            // current robot wins
            s.pop();
            robot.health--;
        }
        if (!s.empty() && s.top().direction == 'R') { // current robot loses
            if (s.top().health == robot.health) {
                // last collision was with a robot of same health, both removed
                s.pop();
            } else {
                // last collision was with a robot of bigger health, it wins
                s.top().health--;
            }
        } else {
            // current robot wins from every robot going right
            // it continues going left towards -infinity
            s.push(robot);
        }
    }

public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string& directions) {
        int n = positions.size();
        vector<Robot> robots(n);
        for (int i = 0; i < n; i++) {
            robots[i] = Robot(positions[i], healths[i], directions[i], i);
        }
        // sort by initial position
        sort(robots.begin(), robots.end(), 
            [](Robot& r1, Robot& r2) { return r1.position < r2.position; });
        stack<Robot> s;
        for (Robot& robot: robots) {
            if (robot.direction == 'R') { // going right
                s.push(robot);
            } else { // going left
                makeCollisions(s, robot);
            }
        }
        robots.clear();
        while (!s.empty()) {
            robots.push_back(s.top());
            s.pop();
        }
        // sort by initial index
        sort(robots.begin(), robots.end(),
            [](Robot& r1, Robot& r2) { return r1.index < r2.index; });
        vector<int> result;
        for (auto& robot: robots) {
            result.push_back(robot.health);
        }
        return result;
    }
};