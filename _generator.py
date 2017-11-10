#!/usr/bin/python
"""
   ------Notebook Generator------
"""
import subprocess
CONTENT_LATEX = "contentNotebook.tex"
TEMPLATE_LATEX = "templateNotebook.tex"
CODES_TREE = "content.txt"
LATEXC = ["latexmk", "-pdf", TEMPLATE_LATEX]

def getSections(secs=[], aux={}, sec_name=None):
    with open(CODES_TREE, 'r') as f:
        for line in f:
            line = line.strip()
            if len(line) == 0: continue
            if (line.startswith("_")): continue
            tmp = line.split('/')
            if len(tmp) == 1: continue;
            if tmp[0] not in aux :
                aux[tmp[0]] = sec_name = tmp[0]
                subsecs = []
                if sec_name is not None: secs.append((sec_name, subsecs))
            filename = tmp[-1]
            subsec_name = ' '.join([x for x in tmp[1:-1]])+" "+ filename.split(".")[0]
            dire = '/'.join([x for x in tmp[:-1]])
            if subsec_name is None: raise ValueError('Subsec given without sec')
            subsecs.append((filename, subsec_name, dire))
    return secs

def getStyle(filename):
    ext = filename.lower().split('.')[-1]
    if ext in ['cc', 'cpp']: return 'cpp'
    elif ext in ['java']: return 'java'
    elif ext in ['py']: return 'py'
    else: return 'txt'

def txt2Latex(secs,  tex=''):
    for (sec_name, subsecs) in secs:
        tex += '\\section{%s}\n' % sec_name
        for (filename, subsec_name, dire) in subsecs:
            tex += '\\subsection{%s}\n' % subsec_name
            tex += '\\raggedbottom\\lstinputlisting[style=%s]{%s/%s}\n' % (getStyle(filename), dire, filename)
            tex += '\\hrulefill\n'
        tex += '\n'
    return tex

if __name__ == "__main__":
    print (__doc__)
    tex = txt2Latex(getSections())
    with open(CONTENT_LATEX, 'w') as f: f.write(tex)
    subprocess.call(LATEXC)
