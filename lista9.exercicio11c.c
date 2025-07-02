void mediaMateria(Materia *m1) {
    for (int i = 0; i < 5; i++) {
        m1->media[i] = 0.0f;
        for (int j = 0; j < m1->nAlunos; j++) {
            m1->media[i] += m1->V[j].vNotas[i];
        }
        m1->media[i] /= m1->nAlunos;
    }
}
