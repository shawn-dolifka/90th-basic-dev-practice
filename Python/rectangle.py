"""see the README.md file for instructions"""
class Rectangle:
    def __init__(self, upperLeft, lowerRight):
        up_left_x = upperLeft[0]
        up_left_y = upperLeft[1]
        low_right_x = lowerRight[0]
        low_right_y = lowerRight[1]

        if (0 > low_right_y < 20 or 0 > low_right_x > 20 or
           0 > up_left_y > 20 or 0 > up_left_x > 20):
            raise ValueError

        else:
            # Set upper left coordinates
            self.upperLeft_x = up_left_x
            self.upperLeft_y = up_left_y
            # Set lower right coordinates
            self.lowerRight_x = low_right_x
            self.lowerRight_y = low_right_y
    
    def length(self):
        side_1 = abs(self.upperLeft_x - self.lowerRight_x)
        side_2 = abs(self.upperLeft_y - self.lowerRight_y)
        if side_1 > side_2:
            return side_1
        else:
            return side_2
    
    def width(self):
        side_1 = abs(self.upperLeft_x - self.lowerRight_x)
        side_2 = abs(self.upperLeft_y - self.lowerRight_y)
        if side_1 < side_2:
            return side_1
        else:
            return side_2
    
    def perimeter(self):
        return 2 * self.length() + 2 * self.width()

    def area(self):
        return self.length() * self.width()

    def isSquare(self):
        if self.length() == self.width():
            return True
        return False
