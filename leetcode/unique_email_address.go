func filterLocal(x string) string {
	res := ""
	for _,j := range x {
		if j=='+' {
			return res
		} else if j=='.' {
			continue
		} else {
			res+=string(j)
		}
	}
	return res
}

func filterDomain(x string) string {
	return x
}

func divide(x string) (string,string) {
	f := ""
	s := ""
	q := false
	for _,j := range x {
		if j=='@' {
			q = true
		} else if !q {
			f+=string(j)
		} else {
			s+=string(j)
		}
	}
	return f,s
}

func concat(x string) string {
	first,second := divide(x)
	first = filterLocal(first)
	second = filterDomain(second)
	return first + "@" + second
}

func numUniqueEmails(emails []string) int {
	m := map[string]int{}
    res := 0
    for _,j := range emails {
		x := j
		y := concat(x)
		if m[y]==0 {
            res++
			m[y] = 1
		}
	}
	return res
}