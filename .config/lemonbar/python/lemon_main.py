class Lemon:
    'Bar structure'
    def __init__(self, pos, sep_l, sep_r, weight, fg_colour, bg_colour):
        self.pos = pos
        self.sep_l = sep_l
        self.sep_r = sep_r
        self.font = font
        self.weight = weight
        self.fg_color = fg_color
        self.bg_color = bg_color
        self.pulp = pulp
        self.seed = seed
    
    def lemon_show(self):
        print(self.pos, self.fg_color, self.bg_color, self.font, self.weight, self.sep_l, self.pulp, self.sep_r)


