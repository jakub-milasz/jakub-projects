import Menu from "../components/Menu";

export default function Kredyty() {
  return (
    <>
      <Menu />
      <main className="spadek">
        <p>
          Klikając w tę sekcję, prawdopodobnie szukasz pomocy w jednej z dwóch
          sytuacji:
        </p>
        <ol>
          <b>
            <li>
              Otrzymałeś oświadczenie o wypowiedzeniu umowy lub sądowy nakaz
              zapłaty
            </li>
          </b>
          <p>
            W tej sytuacji ważne są terminy. Zwłaszcza, gdy doręczono już nakaz
            zapłaty. Aby uniknąć jego prawomocności i egzekucji komorniczej,
            należy złożyć środek zaskarżenia w terminie wskazanym przez sąd
            (zazwyczaj 14 dni od momentu doręczenia nakazu).
          </p>
          <p>
            Bardzo często po złożeniu środka zaskarżenia, na etapie dalszego
            postępowania sądowego{" "}
            <b>
              udaje się zmniejszyć kwotę zadłużenia, która widniała na nakazie
              zapłaty.
            </b>{" "}
            Umowy kredytowe często zawierają bowiem niedozwolone postanowienia
            umowne w zakresie opłat i prowizji, które mogą zostać uznane za
            bezskuteczne. Ponadto, składając środek zaskarżenia od nakazu
            zapłaty można wnieść o <b>rozłożenie zadłużenia na raty</b> tak, by
            nie narazić się na egzekucję komorniczą.
          </p>
          <b>
            <li>
              Masz umowę i chciałbyś sprawdzić czy jej postanowienia są zgodne z
              prawem
            </li>
          </b>
          <p>
            Problem może dotyczyć wielu umów i wielu sytuacji. Rozpoczynając od
            tzw. <b>kredytów frankowych</b>, przez{" "}
            <b>umowy pożyczki z wygórowanymi opłatami</b>, aż po umowy
            niespełniające wymagań ustawowych, które umożliwiają skorzystanie z{" "}
            <b>sankcji kredytu darmowego.</b>
          </p>
          <ul>
            <li>
              <b>Kredyty frankowe</b> to przez ostatnie lata najczęściej
              omawiany temat dotyczący sektora finansowego. Zawarte w umowach
              postanowienia, zgodnie z którymi to bank ustalał kursy walutowe,
              po których dochodziło do wypłaty i spłaty kredytu,{" "}
              <b>
                w zdecydowanej większości dają możliwość unieważnienia umowy w
                całości.
              </b>{" "}
              Sprawa może dotyczyć zarówno kredytów, które są nadal spłacane,
              jak i tych, które zostały już zamknięte. W obu przypadkach można
              domagać się zwrotu nadpłaconych kwot.
            </li>
            <li>
              Nierzadko banki, a w szczególności tzw. parabanki, naliczają
              wygórowane opłaty i prowizje za udzielenie pożyczki. W wielu
              sytuacjach kwota jest na tyle duża, że{" "}
              <b>sąd może uznać takie postanowienie za niedozwolone</b> i
              bezskuteczne w stosunku do kredytobiorcy. W takiej sytuacji
              istnieje więc szansa obniżenia kwoty zadłużenia i zmniejszenia
              comiesięcznego obciążenia budżetu.
            </li>
            <li>
              W ostatnim czasie na popularności zyskuje także instytucja{" "}
              <b>sankcji kredytu darmowego.</b> Skorzystać z niej mogą
              kredytobiorcy, których umowa nie spełnia wymagań wskazanych w
              ustawie o kredycie konsumenckim. W takiej sytuacji należy w
              odpowiednim terminie złożyć oświadczenie o skorzystaniu z sankcji
              kredytu darmowego. Po skutecznym złożeniu takiego oświadczenia,
              kredytobiorca zwraca wyłącznie kwotę kapitału, bez odsetek,
              prowizji i innych opłat. W większości przypadków Bank nie
              zaakceptuje złożonego oświadczenia, wobec czego konieczne będzie
              wytoczenie powództwa i przeprowadzenie postępowania przed sądem.
            </li>
          </ul>
        </ol>
        <p className="foot">
          Każda sprawa dotycząca umów kredytowych i pożyczkowych wymaga
          szczegółowej analizy. Podczas rozmowy przedstawię, jak wygląda
          sytuacja Twojej sprawie, czego można się spodziewać na dalszym etapie
          postępowania i jakie są szanse na zmniejszenie zadłużenia lub
          odzyskanie nienależnie pobranych przez bank pieniędzy.
        </p>
      </main>
    </>
  );
}
