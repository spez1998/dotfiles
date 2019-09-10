class Bar:
    def __init__(self, admiral_conf, width, height, pad_width, pad_height, bg_color_base, fg_color_base, font_1, font_2, clicks):
        self.admiral_conf = admiral_conf
        self.width = width
        self.height = height
        self.pad_width = pad_width
        self.pad_height = pad_height
        self.bg_color_base = bg_color_base
        self.fg_color_base = fg_color_base
        self.font_1 = font_1
        self.font_2 = font_2
        self.clicks = clicks

    def show(self):
        print("admiral -c "+self.admiral_conf+" | lemonbar -p -g "+self.width+"x"+self.height+"+"+self.pad_width+"x"+self.pad_height+" -f "+self.font_1+" -f "+self.font_2+" -F "+self.fg_color_base+" -a "+self.clicks+" | sh &")

bar_main = Bar("/home/sujit/.config/admiral.d/admiral_main.toml", "1920", "20", "0", "0", "'#00000000'", "'#ebdbb2'", "-misc-tamzenforpowerline-medium-r-normal--20-145-100-100-c-100-iso8859-1", "-misc-tamzenforpowerline-bold-r-normal--20-145-100-100-c-100-iso8859-1", "21")
bar_main.show()
