# text-generator (ENG)
Simple text generator, based on Markov chains.\n
Developed on C++ using STL.
My idea is about reading all the text, and count all the transitions between the words. After that, we have nxn matrix of a Markov chain. We can generate(using random distribution from matrix) next word if we know current. 
To quick start, you need put your text/books in dataset folder(by default it's Harry Potter books), and then run a program.
It will generate about 100 words, learned on text from dataset folder.

# text-generator(RUS)
Простой генератор текста, построенный на модели цепи Маркова. 
Программа написана на С++ с использованием STL(распределения случайных величин).
Идея состоит в том, чтобы прочитать весь текст, составить матрицу переходов между словами(подсчитать количество). Сделав это, мы имеем матрицу цепи Маркова, то есть можем генеририровать следующее слово по предыдущему.
Для демонстрации работы, вы должны переместить обучающую литературу(по умолчанию это книги Гарри Поттер), затем запустите программу. Она сгенерирует около 100 слов(на основе полученных вероятностей)
