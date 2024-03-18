-- INT TABELA
create table usuarios
(
	cpf integer,
  	nome varchar(50),
  	sobrenome varchar(50),
  	cargo varchar(50),
	curso_id integer
);

create table cursos
(
	id integer
  	nome_curso varchar(50),
  	professor varchar(50),
  	categoria varchar(50)
);

insert into usuarios (cpf,nome,sobrenome,cargo,curso_id)
values ('123','Gui','Delfes','aluno','1');

insert into usuarios (cpf,nome,sobrenome,cargo,curso_id)
values ('1234','Bruna','Delfes','professor,'2');

insert into usuarios (cpf,nome,sobrenome,cargo,curso_id)
values ('12345','Bruno','Delfes','professor','3');

insert into cursos (id,nome_curso,professor, categoria)
values ('1','TI do Zero','Bruno Delfes','Progamação');
        
insert into cursos (id,nome_curso,professor, categoria)
values ('2','SQL','Bruna Delfes','Dados');        