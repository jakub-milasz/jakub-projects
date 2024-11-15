import Menu from "../components/Menu";
import { useEffect, useRef } from "react";

export default function Rozwod() {
  return (
    <>
      <Menu />
      <main className="spadek">
        <p>
          W zależności od okoliczności, sprawy rozwodowe mogą znacznie się
          różnić. Sąd podczas postępowania rozwodowego co do zasady orzeka o
          kilku kwestiach:
        </p>
        <ol>
          <li>Rozwiązanie małżeństwa</li>
          <p>
            Sąd przede wszystkim bada czy pomiędzy małżonkami nastąpił trwały i
            zupełny rozkład pożycia małżeńskiego, rozumiany jako ustanie
            wszelkich relacji fizycznych, emocjonalnych czy gospodarczych. W
            przypadku, gdy małżonkowie mają małoletnie dzieci sąd dodatkowo bada
            czy poprzez orzeczenie rozwodu nie ucierpi ich dobro.
          </p>
          <li>Wina</li>
          <p>
            W przypadku rozwodu z orzekaniem o winie, sprawa wymaga
            przeprowadzenia przed sądem postępowania dowodowego, którego celem
            będzie wykazanie winy jednego z małżonków. Jeżeli małżonkowie
            zdecydują się na rozwód bez orzekania o winie, wówczas sprawa może
            się zakończyć już po jednej rozprawie.
          </p>
          <p>Co daje orzeczenie o winie?</p>
          <p>
            Wbrew pozorom orzeczenie o winie nie przynosi wielu wymiernych
            korzyści. Nie ma ono bezpośredniego wpływu na kwestię władzy
            rodzicielskiej, kontaktów z dzieckiem czy alimentów na dziecko.
          </p>
          <p>
            Orzeczenie o winie daje jednak małżonkowi niewinnemu możliwość
            domagania się zasądzenia alimentów na siebie. W przypadku bowiem,
            gdy sąd uzna jednego z małżonków za wyłącznie winnego rozkładu
            pożycia, wówczas drugi może żądać zasądzenia alimentów na swoją
            rzecz. Jednakże jest to możliwe wyłącznie, gdy rozwód powoduje
            pogorszenie sytuacji materialnej małżonka niewinnego. Należy więc
            mieć na uwadze, że w sytuacji, gdy oboje małżonkowie mają podobne
            dochody, wówczas sąd nie zasądzi alimentów, pomimo orzeczenia o
            winie.
          </p>
          <li>Małoletnie dzieci – władza rodzicielska, kontakty, alimenty</li>
          <p>
            W sytuacji, gdy małżonkowie mają małoletnie dzieci, sąd orzeknie o
            władzy rodzicielskiej, miejscu zamieszkania dziecka i kontaktach z
            drugim rodzicem. Sąd orzeknie również o alimentach na dziecko i ich
            wysokości. W tych kwestiach sąd przede wszystkim bierze pod uwagę
            dobro małoletniego dziecka.
          </p>
          <li>Korzystanie ze wspólnego mieszkania</li>
          <p>
            W wyjątkowych sytuacjach, gdy małżonkowie pomimo złożenia pozwu o
            rozwód nadal mieszkają razem i istnieje duże prawdopodobieństwo, że
            po rozwodzie nadal będą tam mieszkać, sąd orzeknie kto i w jakim
            zakresie może korzystać ze wspólnego mieszkania. Jeżeli jeden ze
            współmałżonków swoim rażąco nagannym postępowaniem uniemożliwia
            wspólne zamieszkiwanie, sąd może nakazać jego eksmisję.
          </p>
          <li>Podział majątku wspólnego</li>
          <p>
            Co do zasady podział majątku wspólnego nie odbywa się w postępowaniu
            rozwodowym. Jednakże, gdy majątek wspólny nie jest duży, a między
            stronami nie ma sporu w tym zakresie, istnieje możliwość, aby sąd
            już w wyroku rozwodowym orzekł także w tej sprawie.
          </p>
          <p>
            Jeżeli jednak sąd uzna, że rozstrzygnięcie tej kwestii mogłoby
            spowodować zwłokę w postępowaniu rozwodowym, wówczas odmówi
            dokonania podziału majątku. W takiej sytuacji, po uprawomocnieniu
            się wyroku rozwodowego, konieczne będzie wszczęcie odrębnego
            postępowania o podział majątku wspólnego.
          </p>
        </ol>
        <p className="foot">
          Podczas naszej rozmowy odpowiem na wszelkie pytania dotyczące
          opisanych wyżej kwestii. Przedstawię cały proces, wysokość opłat
          sądowych i szacowany czas rozstrzygnięcia sprawy.
        </p>
      </main>
    </>
  );
}
