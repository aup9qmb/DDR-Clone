
class conductor(object):
    def __init__(self):
        self.bpm = 0            # bpm of song
        self.crochet = 0        # time duration of a beat, calc from bpm
        self.songposition = 0
        self.offset = 0         # positive by convention, will be subtracted
        self.beatnumber = 0

    