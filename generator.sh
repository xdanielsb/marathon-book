find . | grep  -E "\.(cpp|java|py)$" | cut -c3-100  | sort > content.txt

python _generator.py &&  rm content.txt && mv templateNotebook.pdf book.pdf && mv book.pdf Notebook/ && gnome-open Notebook/book.pdf

rm templateNotebook.log
rm templateNotebook.out
rm templateNotebook.toc
rm templateNotebook.aux
rm templateNotebook.fdb_latexmk
rm templateNotebook.fls
