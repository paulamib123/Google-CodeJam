def pickLetter(s, letter):
    if s[0] == letter or s[-1] == letter:
        if s[0] == s[1]:
            new = s[1:]
        else if s[-2] == s[-1]:
            new = s[:-1]
        else if s[0] == letter:
            new = s[1:]
        else if s[-1] == letter:
            new = s[:-1]
    return new

def irefutableOutcome(s):
    
