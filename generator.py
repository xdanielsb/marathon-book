#!/usr/bin/python
import subprocess
code_dir = "code"
title = "Stanford ACM-ICPC Team Notebook"

def get_sections():
    sections = []
    aux  = {}
    section_name = None
    with open('content.txt', 'r') as f:
        for line in f:
            if '#' in line: line = line[:line.find('#')]
            line = line.strip()
            if len(line) == 0: continue
            tmp = line.split('/')
            if len(tmp) == 1: continue;

            if tmp[0] not in aux :
                aux[tmp[0]] = tmp[0]
                section_name = tmp[0]
                subsections = []
                if section_name is not None:
                    sections.append((section_name, subsections))
            else:
                print(tmp)
                if len(tmp) == 1: continue;
                filename = tmp[-1]
                subsection_name = ' '.join([x for x in tmp[:-1]])+" "+ filename.split(".")[0]
                dire = '/'.join([x for x in tmp[:-1]])

                if subsection_name is None:
                    raise ValueError('Subsection given without section')
                subsections.append((filename, subsection_name, dire))
    return sections

def get_style(filename):
    ext = filename.lower().split('.')[-1]
    if ext in ['c', 'cc', 'cpp']:
        return 'cpp'
    elif ext in ['java']:
        return 'java'
    elif ext in ['py']:
        return 'py'
    else:
        return 'txt'

# TODO: check if this is everything we need
def texify(s):
    #s = s.replace('\'', '\\\'')
    #s = s.replace('\"', '\\\"')
    return s

def get_tex(sections):
    tex = ''
    for (section_name, subsections) in sections:
        tex += '\\section{%s}\n' % texify(section_name)
        for (filename, subsection_name, dire) in subsections:
            tex += '\\subsection{%s}\n' % texify(subsection_name)
            tex += '\\raggedbottom\\lstinputlisting[style=%s]{%s/%s}\n' % (get_style(filename), dire, filename)
            tex += '\\hrulefill\n'
        tex += '\n'
    return tex

if __name__ == "__main__":
    sections = get_sections()
    tex = get_tex(sections)
    print (tex)
    with open('contentNotebook.tex', 'w') as f:
        f.write(tex)
    latexmk_options = ["latexmk", "-pdf", "templateNotebook.tex"]
    subprocess.call(latexmk_options)
